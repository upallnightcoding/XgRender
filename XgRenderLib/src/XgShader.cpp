#include "XgShader.h"

//#include <fstream>
//#include <sstream>
//#include <string>
//#include <cerrno>

#include "Xg.h"
#include "XgConstants.h"
//#include "XgKeyboardEvent.h"

XgShader::XgShader(std::string pathName)
{
	this->pathName = pathName;
}

XgShader::~XgShader()
{
}

/*****************************************************************************
use() -
*****************************************************************************/
void XgShader::use()
{
	glUseProgram(shaderProgram);
}

/*****************************************************************************
uniform() -
*****************************************************************************/
void XgShader::create()
{
	std::string path = XgConstant::SOLUTION_DIR + XgConstant::SHADER_DIRECTORY;
	std::string filename = pathName;
	std::string source = readShaderFile(path + filename);
	size_t seperator = source.find("@");
	std::string vertexSource = source.substr(0, seperator);
	std::string fragmentSource = source.substr(seperator + 1, source.length());

	std::cout << "VertexSoure: \n" << vertexSource << std::endl;
	std::cout << "FragmentSource: \n" << fragmentSource << std::endl;

	const char *vertexShaderSource = vertexSource.c_str();
	const char *fragmentShaderSource = fragmentSource.c_str();

	int vertexShader = compile(vertexShaderSource, GL_VERTEX_SHADER);
	int fragmentShader = compile(fragmentShaderSource, GL_FRAGMENT_SHADER);

	link(vertexShader, fragmentShader);
}

/*****************************************************************************
uniform() -
*****************************************************************************/
void XgShader::uniform(std::string name, glm::vec4 colour)
{
	//int location = glGetUniformLocation(shaderProgram, name.c_str());
	//glUniform4f(location, colour.r, colour.g, colour.b, colour.a);
}

/*****************************************************************************
uniform() -
*****************************************************************************/
void XgShader::uniform(std::string name, glm::vec3 value)
{
	int location = glGetUniformLocation(shaderProgram, name.c_str());
	glUniform3f(location, value.x, value.y, value.z);
}

/*****************************************************************************
uniform() -
*****************************************************************************/
void XgShader::uniform(std::string name, glm::mat4 value)
{
	int location = glGetUniformLocation(shaderProgram, name.c_str());
	glUniformMatrix4fv(location, 1, GL_FALSE, value_ptr(value));
}

/*****************************************************************************
uniform() -
*****************************************************************************/
void XgShader::uniform(std::string name, int value)
{
	int location = glGetUniformLocation(shaderProgram, name.c_str());
	glUniform1i(location, value);
}

/*****************************************************************************
uniform() -
*****************************************************************************/
void XgShader::uniform(std::string name, float value)
{
	int location = glGetUniformLocation(shaderProgram, name.c_str());
	glUniform1f(location, value);
}

/*****************************************************************************
link() -
*****************************************************************************/
void XgShader::link(int vertexShader, int fragmentShader)
{
	// Link the Vertex and Fragment Shaders
	//-------------------------------------
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	// Check for any linking errors
	//-----------------------------
	int success;
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);

	if (!success) {
		char infoLog[512];
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}

	// Free shader memory and associated name
	//---------------------------------------
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

/*****************************************************************************
compile() - Compiles the source shader and defines a shader id that is 
returned to the caller.  If there is an error in the compilation a message is
written to standard output.  Upon an error the shader id is also set to -1.
*****************************************************************************/
int XgShader::compile(const char *source, GLenum shaderType)
{
	// Create the shader id and attempt to compile the source
	//-------------------------------------------------------
	int shaderId = glCreateShader(shaderType);
	glShaderSource(shaderId, 1, &source, NULL);
	glCompileShader(shaderId);

	// Write to standard output any shader compilation errors
	//-------------------------------------------------------
	int success;
	glGetShaderiv(shaderId, GL_COMPILE_STATUS, &success);

	if (!success) {
		char infoLog[512];
		glGetShaderInfoLog(shaderId, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::COMPILATION_FAILED\n" << infoLog << std::endl;
		shaderId = -1;
	}

	return(shaderId);
}

/*****************************************************************************
readShaderFile() - Reads the entire content of the shader file.  The content
is read in as a "ostringstream" and then converted to a string.  Any exception
is not handled and returns back to the caller.
*****************************************************************************/
std::string XgShader::readShaderFile(const std::string pathname)
{
	std::string source = "";

	std::ifstream in(pathname, std::ios::in | std::ios::binary);

	if (in) {
		std::ostringstream contents;
		contents << in.rdbuf();
		in.close();
		source = contents.str();
	}
	
	return(source);
}
