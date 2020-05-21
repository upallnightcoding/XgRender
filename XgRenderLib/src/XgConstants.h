#pragma once

#include "Xg.h"

// Application Level Constants
//----------------------------
namespace XgConstant {
	// Default width and height of the pixel screen
	//---------------------------------------------
	constexpr int SCREEN_WIDTH = 600;
	constexpr int SCREEN_HEIGHT = 600;

	// Application Directory Locations
	//--------------------------------
	const std::string SOLUTION_DIR = 
		"C:\\Users\\Ken\\Desktop\\SandBox\\programming\\c++\\XgPixel\\XgPixelTestBed\\";

	// Application Resource Directories
	//---------------------------------
	const std::string SHADER_DIRECTORY = "shaders\\";
	const std::string IMAGE_DIRECTORY = "images\\";
	const std::string MODEL_DIRECTORY = "models\\";

	// General Shaders Title
	//----------------------
	const std::string SPRITE_SHADER = "sprite.shader";

	// Shader Uniform Constants
	//-------------------------
	const std::string UNIFORM_TRANSFORM = "u_Transform";

	const std::string EMPTY_STRING = "";

	const int NO_FLIP_BOOK = (-1);
}