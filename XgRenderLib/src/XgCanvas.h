#pragma once
//#include "C:\Users\Ken\Desktop\SandBox\programming\c++\XgRender\resources\wxWidgets-3.1.3\include\wx\msw\glcanvas.h"

#include "wx/wx.h"
#include "wx/glcanvas.h"

#include "XgMessagePanel.h"

class XgCanvas :
	public wxGLCanvas
{
public:
	XgCanvas(wxWindow* parent, int* args);
	virtual ~XgCanvas();

public:
	void resized(wxSizeEvent& evt);

	int getWidth();
	int getHeight();

	void render(wxPaintEvent& evt);
	void prepare3DViewport(int topleft_x, int topleft_y, int bottomrigth_x, int bottomrigth_y);
	void prepare2DViewport(int topleft_x, int topleft_y, int bottomrigth_x, int bottomrigth_y);

	// events
	void mouseMoved(wxMouseEvent& event);
	void mouseDown(wxMouseEvent& event);
	void mouseWheelMoved(wxMouseEvent& event);
	void mouseReleased(wxMouseEvent& event);
	void rightClick(wxMouseEvent& event);
	void mouseLeftWindow(wxMouseEvent& event);
	void keyPressed(wxKeyEvent& event);
	void keyReleased(wxKeyEvent& event);

	void set(XgMessagePanel *messagePanel);

private:
	void OnSpinTimer(wxTimerEvent& WXUNUSED(event));

	wxDECLARE_EVENT_TABLE();

private:
	wxGLContext*	glContext;
	GLfloat rotate = 0.0;
	wxTimer m_spinTimer;
	XgMessagePanel *messagePanel;

	double deltaTime;
	int tickCount;
	int fps;
	double limitFPS;

	double lastTime;
	double timer;
	double nowTime;
};

inline void XgCanvas::set(XgMessagePanel *messagePanel) 
{
	this->messagePanel = messagePanel;
}



