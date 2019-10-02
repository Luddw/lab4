//------------------------------------------------------------------------------
// Lab3.cc
// (C) 2015-2018 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include "config.h"
#include "lab3.h"

#include <cstring>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

#include <GL/glew.h>


const GLchar* vs =
	"#version 430\n"
	"layout(location=0) in vec3 pos;\n"
	"layout(location=1) in vec2 uv;\n"
	"layout(location=0) uniform mat4 mv;\n"
	"layout(location=1) uniform mat4 proj;\n"
	"layout(location=1) out vec2 UV;\n"
	"void main()\n"
	"{\n"
	"	gl_Position = proj*mv*vec4(pos, 1);\n"
	"	UV = uv;\n"
	"}\n";

const GLchar* ps =
	"#version 430\n"
	"layout(location=1) in vec2 UV;\n"
	"uniform sampler2D text;\n"
	"out vec4 Color;\n"
	"void main()\n"
	"{\n"
	"	Color = texture2D(text,UV);\n"
	"}\n";

using namespace Display;

namespace Example
{
	//------------------------------------------------------------------------------
	/**
	*/
	Lab3::Lab3()
	{
		// empty
	}

	//------------------------------------------------------------------------------
	/**
	*/
	Lab3::~Lab3()
	{
		// empty
	}

	//------------------------------------------------------------------------------
	/**
	*/
	bool
	Lab3::Open()
	{
		App::Open();
		this->window = new Window;
		window->SetKeyPressFunction([this](int32, int32, int32, int32)
		{
			this->window->Close();
		});


		if (this->window->Open())
		{
			glEnable(GL_DEPTH_TEST);
			glDepthFunc(GL_LESS);

			return true;
		}
		return false;
	}

	//------------------------------------------------------------------------------
	/**
	*/
	Matrix4D Lookat(Vector4D eye, const Vector4D& at, const Vector4D& up)
	{
		Vector4D z_axis = (eye - at);
		z_axis = z_axis.Normalize();
		Vector4D x_axis = z_axis.CrossProduct(up);
		x_axis = x_axis.Normalize();
		Vector4D y_axis = x_axis.CrossProduct(z_axis);
		const Matrix4D viewmat(
			x_axis.GetX(), x_axis.GetY(), x_axis.GetZ(), -1 * x_axis.DotProduct(eye),
			y_axis.GetX(), y_axis.GetY(), y_axis.GetZ(), -1 * y_axis.DotProduct(eye),
			z_axis.GetX(), z_axis.GetY(), z_axis.GetZ(), -1 * z_axis.DotProduct(eye),
			0, 0, 0, 1

		);

		return viewmat;
	}

	void
	Lab3::Run()
	{
		Texture tex("../texture1.png");
		ShaderResource shad("../../resources/shader.glsl");

		Vector4D cam(0, 0.4f, 0.7f, 1.0f);
		Matrix4D view;
		float angle = 0.05f;
		Matrix4D rot;
		Matrix4D rot2;
		Matrix4D model;
		Matrix4D proj = Matrix4D::PerspProj(1.5707f, (static_cast<float>(4) / static_cast<float>(3)), 0.1f, 100.0f);
		Matrix4D mv;
		shad.Bind();

		tex.Bind(0);
		rot = rot.RotY_axis(-0.01f);

		while (this->window->IsOpen())
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


			cam = rot * cam;
			view = Lookat(cam, Vector4D(0, 0, 0), Vector4D(0, 1, 0));
			mv = view * model;
			shad.SetUniformMatrix4fv("mv", mv);
			shad.SetUniformMatrix4fv("proj", proj);


			mesh.DrawCube(0.5f);


			this->window->Update();
			this->window->SwapBuffers();
		}
	}
} // namespace Example
