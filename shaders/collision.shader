#version 330 core

// VAO Layout Locations
//---------------------
layout (location = 0) in vec3 aPosition;
//layout (location = 1) in vec3 aColor;
//layout (location = 2) in vec2 aTexCoord;

// Object Uniform Variables
//-------------------------
uniform mat4 u_Transform;
uniform mat4 u_View;
uniform mat4 u_Projection;

void main()
{
	gl_Position = u_Projection * u_View * u_Transform * vec4(aPosition, 1.0);
	//gl_Position = u_Projection * u_View * vec4(aPosition, 1.0);
}
@
#version 330 core
out vec4 FragColor;

void main()
{
	vec4 texColor = vec4(1.0, 1.0, 1.0, 0.0);
		
    FragColor = texColor;
}
