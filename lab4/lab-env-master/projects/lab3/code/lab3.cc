//------------------------------------------------------------------------------
// Lab3.cc
// (C) 2015-2018 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include "config.h"
#include "lab3.h"
#include <sstream>
#include <GL/glew.h>
#include "graphicnode.h"




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
			glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

			glEnable(GL_DEPTH_TEST);
			glDepthFunc(GL_LESS);

			return true;
		}
		
		return false;
	}

	//------------------------------------------------------------------------------
	/**
	*/

	void
	Lab3::Run()
	{
		Matrix4D m;
		Matrix4D rot;
		Matrix4D rot2;
		
		

		Vector4D startcam(0, 0.8f, 2, 1);
		auto mesh = std::make_shared<MeshResource>();
		auto tex = std::make_shared<Texture>("../texture1.png");
		auto shad = std::make_shared<ShaderResource>("../shader.glsl");
		auto tran = std::make_shared<Transform>(m,m,m);
		auto cam = std::make_shared<Cam>(startcam,Vector4D(0,0,0,1));
		
		GraphicNode node(mesh, tex, shad, tran, cam);
		
		//GraphicNode lel(mesh, tex, shad, tran, cam);

		
		while (this->window->IsOpen())
		{

			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			node.Draw();
			tran->RotY(0.01);
			

			//lel.Draw();
			this->window->Update();
			this->window->SwapBuffers();
		}
	}
} // namespace Example
