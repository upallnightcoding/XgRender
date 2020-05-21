#include "XgCanvas.h"

#ifdef __WXMAC__
#include "OpenGL/glu.h"
#include "OpenGL/gl.h"
#else
#include <GL/glu.h>
#include <GL/gl.h>
#endif

BEGIN_EVENT_TABLE(XgCanvas, wxGLCanvas)
EVT_MOTION(XgCanvas::mouseMoved)
EVT_LEFT_DOWN(XgCanvas::mouseDown)
EVT_LEFT_UP(XgCanvas::mouseReleased)
EVT_RIGHT_DOWN(XgCanvas::rightClick)
EVT_LEAVE_WINDOW(XgCanvas::mouseLeftWindow)
EVT_SIZE(XgCanvas::resized)
EVT_KEY_DOWN(XgCanvas::keyPressed)
EVT_KEY_UP(XgCanvas::keyReleased)
EVT_MOUSEWHEEL(XgCanvas::mouseWheelMoved)
EVT_PAINT(XgCanvas::render)
END_EVENT_TABLE()

GLfloat data[8][3];
GLint testfaces[6][4] = {  /* Vertex indices for the 6 testfaces of a cube. */
	{0, 1, 2, 3}, {3, 2, 6, 7}, {7, 6, 5, 4},
	{4, 5, 1, 0}, {5, 6, 2, 1}, {7, 4, 0, 3} };

//XgCanvas::XgCanvas(wxFrame* parent, int* args) :
	//wxGLCanvas(parent, wxID_ANY, args, wxDefaultPosition, wxDefaultSize, wxFULL_REPAINT_ON_RESIZE)
XgCanvas::XgCanvas(wxWindow* parent, int* args) :
	wxGLCanvas(parent, wxID_ANY, args, wxDefaultPosition, wxDefaultSize, wxFULL_REPAINT_ON_RESIZE)
{
	m_context = new wxGLContext(this);
	// prepare a simple cube to demonstrate 3D render
	// source: http://www.opengl.org/resources/code/samples/glut_examples/examples/cube.c
	data[0][0] = data[1][0] = data[2][0] = data[3][0] = -1.0;
	data[4][0] = data[5][0] = data[6][0] = data[7][0] = 1;
	data[0][1] = data[1][1] = data[4][1] = data[5][1] = -1;
	data[2][1] = data[3][1] = data[6][1] = data[7][1] = 1;
	data[0][2] = data[3][2] = data[4][2] = data[7][2] = 1;
	data[1][2] = data[2][2] = data[5][2] = data[6][2] = -1;

	// To avoid flashing on MSW
	SetBackgroundStyle(wxBG_STYLE_CUSTOM);
}

XgCanvas::~XgCanvas()
{
	delete m_context;
}

void XgCanvas::mouseMoved(wxMouseEvent& event) 
{
	Refresh();
}
void XgCanvas::mouseDown(wxMouseEvent& event) {}
void XgCanvas::mouseWheelMoved(wxMouseEvent& event) {}
void XgCanvas::mouseReleased(wxMouseEvent& event) {}
void XgCanvas::rightClick(wxMouseEvent& event) {}
void XgCanvas::mouseLeftWindow(wxMouseEvent& event) {}
void XgCanvas::keyPressed(wxKeyEvent& event) {}
void XgCanvas::keyReleased(wxKeyEvent& event) {}

void XgCanvas::resized(wxSizeEvent& evt)
{
	//	wxGLCanvas::OnSize(evt);

	Refresh();
}

/** Inits the OpenGL viewport for drawing in 3D. */
void XgCanvas::prepare3DViewport(int topleft_x, int topleft_y, int bottomrigth_x, int bottomrigth_y)
{

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black Background
	glClearDepth(1.0f);	// Depth Buffer Setup
	glEnable(GL_DEPTH_TEST); // Enables Depth Testing
	glDepthFunc(GL_LEQUAL); // The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_COLOR_MATERIAL);

	glViewport(topleft_x, topleft_y, bottomrigth_x - topleft_x, bottomrigth_y - topleft_y);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	float ratio_w_h = (float)(bottomrigth_x - topleft_x) / (float)(bottomrigth_y - topleft_y);
	gluPerspective(45 /*view angle*/, ratio_w_h, 0.1 /*clip close*/, 200 /*clip far*/);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}

/** Inits the OpenGL viewport for drawing in 2D. */
void XgCanvas::prepare2DViewport(int topleft_x, int topleft_y, int bottomrigth_x, int bottomrigth_y)
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black Background
	glEnable(GL_TEXTURE_2D);   // textures
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_BLEND);
	glDisable(GL_DEPTH_TEST);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glViewport(topleft_x, topleft_y, bottomrigth_x - topleft_x, bottomrigth_y - topleft_y);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluOrtho2D(topleft_x, bottomrigth_x, bottomrigth_y, topleft_y);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int XgCanvas::getWidth()
{
	return GetSize().x;
}

int XgCanvas::getHeight()
{
	return GetSize().y;
}


void XgCanvas::render(wxPaintEvent& evt)
{
	if (!IsShown()) return;

	wxGLCanvas::SetCurrent(*m_context);
	wxPaintDC(this); // only to be used in paint events. use wxClientDC to paint outside the paint event

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// ------------- draw some 2D ----------------
	prepare2DViewport(0, 0, getWidth() / 2, getHeight());
	glLoadIdentity();

	// white background
	glColor4f(1, 1, 1, 1);
	glBegin(GL_QUADS);
	glVertex3f(0, 0, 0);
	glVertex3f(getWidth(), 0, 0);
	glVertex3f(getWidth(), getHeight(), 0);
	glVertex3f(0, getHeight(), 0);
	glEnd();

	// red square
	glColor4f(1, 0, 0, 1);
	glBegin(GL_QUADS);
	glVertex3f(getWidth() / 8, getHeight() / 3, 0);
	glVertex3f(getWidth() * 3 / 8, getHeight() / 3, 0);
	glVertex3f(getWidth() * 3 / 8, getHeight() * 2 / 3, 0);
	glVertex3f(getWidth() / 8, getHeight() * 2 / 3, 0);
	glEnd();

	// ------------- draw some 3D ----------------
	prepare3DViewport(getWidth() / 2, 0, getWidth(), getHeight());
	glLoadIdentity();

	glColor4f(0, 0, 1, 1);
	glTranslatef(0, 0, -5);
	glRotatef(rotate, 0.0f, 1.0f, 0.0f);

	rotate += 1.0f;

	glColor4f(1, 0, 0, 1);
	for (int i = 0; i < 6; i++)
	{
		glBegin(GL_LINE_STRIP);
		glVertex3fv(&data[testfaces[i][0]][0]);
		glVertex3fv(&data[testfaces[i][1]][0]);
		glVertex3fv(&data[testfaces[i][2]][0]);
		glVertex3fv(&data[testfaces[i][3]][0]);
		glVertex3fv(&data[testfaces[i][0]][0]);
		glEnd();
	}

	glFlush();
	SwapBuffers();
}
