#include "XgSprite.h"

//#define STB_IMAGE_IMPLEMENTATION
//#include "stb_image.h"

#include "XgConstants.h"

XgSprite::XgSprite(std::string texturePath)
{
	this->imagePath =
		XgConstant::SOLUTION_DIR + XgConstant::IMAGE_DIRECTORY + texturePath;
}

XgSprite::~XgSprite()
{

}

/*****************************************************************************
getHeightWidthRatio() -
*****************************************************************************/
float XgSprite::getHeightWidthRatio()
{
	return((float) height / (float) width);
}

/*****************************************************************************
create() - 
*****************************************************************************/
void XgSprite::create()
{
	dataFormat();

	loadTexture();

	//glBindVertexArray(0);
}

/*****************************************************************************
formatData() - Creates the object vao
*****************************************************************************/
void XgSprite::dataFormat()
{
	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);
	glGenBuffers(1, &ebo);

	std::cout << "Generate vao: " << vao << std::endl;

	glBindVertexArray(vao);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_DYNAMIC_DRAW);

	// Position Attribute
	//-------------------
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// Color Attribute
	//----------------
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	// Texture Corrdinate Attribute
	//-----------------------------
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);
}

/******************************************************************************
create() -
******************************************************************************/
void XgSprite::loadTexture()
{
	// Generate Textures  
	//------------------
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture); 

	// Set the texture wrapping parameters
	//------------------------------------
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	// Set the texture filtering parameters
	//-------------------------------------
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	//stbi_set_flip_vertically_on_load(true);

	// Load image, create texture and generate mipmaps
	//------------------------------------------------
	//int nrChannels;
	//unsigned char *data = stbi_load(imagePath.c_str(), &width, &height, &nrChannels, STBI_rgb_alpha);

	//if (data) {
		//glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		//glGenerateMipmap(GL_TEXTURE_2D);
	//} else {
		//std::cout << "Failed to load texture:" << stbi_failure_reason() << std::endl;
	//}

	//stbi_image_free(data);
}

void XgSprite::bindVao()
{
	glBindVertexArray(vao);

	std::cout << "Bind: " << vao << std::endl;
}

/******************************************************************************
draw() -
******************************************************************************/
void XgSprite::draw()
{
	

	glBindTextureUnit(GL_TEXTURE_2D, texture);
	//glBindTexture(GL_TEXTURE_2D, texture);

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

/******************************************************************************
collision() -
******************************************************************************/
void XgSprite::collision()
{
	//glBindVertexArray(vao);

	glDrawArrays(GL_LINE_LOOP, 0, 4);
}

/*****************************************************************************
add() -
*****************************************************************************/
void XgSprite::dispose()
{
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &vbo);
	glDeleteBuffers(1, &ebo);
}

/*****************************************************************************
worldCord() -
*****************************************************************************/
void  XgSprite::worldCord(XgTransform &transform)
{
	glm::vec4 p0 = { 1.0f,  1.0f, 0.0f, 1.0f};
	glm::vec4 p1 = { 1.0f, -1.0f, 0.0f, 1.0f};
	glm::vec4 p2 = {-1.0f, -1.0f, 0.0f, 1.0f};
	glm::vec4 p3 = {-1.0f,  1.0f, 0.0f, 1.0f};

	glm::mat4 worldCordinate = transform.getTransformMatrix();

	p0 = worldCordinate * p0;
	p1 = worldCordinate * p1;
	p2 = worldCordinate * p2;
	p3 = worldCordinate * p3;

	float* vertices = (float*) glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);

	if (vertices) {
		vertices[ 0] = p0[0];
		vertices[ 1] = p0[1];
		vertices[ 2] = p0[2];

		vertices[ 8] = p1[0];
		vertices[ 9] = p1[1];
		vertices[10] = p1[2];

		vertices[16] = p2[0];
		vertices[17] = p2[1];
		vertices[18] = p2[2];

		vertices[24] = p3[0];
		vertices[25] = p3[1];
		vertices[26] = p3[2];

		glUnmapBuffer(GL_ARRAY_BUFFER);
	}
}