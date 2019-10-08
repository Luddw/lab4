//------------------------------------------------------------------------------
// Lab3.cc
// (C) 2015-2018 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include "config.h"
#include "lab3.h"
#include <sstream>
#include <GL/glew.h>
#include <iostream>


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
	void Lab3::keyEvent(int key, int action, int modifier)
	{

	}
	void Lab3::MousePos(float xpos, float ypos)
	{

	}
	//------------------------------------------------------------------------------
	/**
	*/
	
	bool
	Lab3::Open()
	{
		App::Open();
		
		this->window = new Window;
		int w, h;
		this->window->GetSize(w, h);
		window->SetKeyPressFunction([this](int32 key, int32, int32 action, int32 mod)
		{
			this->keyEvent(key, action, mod);
			std::cout <<"Key: "<< key << " action: "<<action << std::endl;
			if (action == 1)
			{
				
				switch (key)
				{
				case GLFW_KEY_D: cubenode.GetTransform()->Move(-0.5f, 0, 0); 
				case GLFW_KEY_A: cubenode.GetTransform()->Move(0.6f, 0, 0); 
				case GLFW_KEY_S: cubenode.GetTransform()->Move(0, 0, 0.1f); 
				case GLFW_KEY_W: cubenode.GetTransform()->Move(0, 0, -0.1f); 
				default: break;
				}
			}
		
			
		}
		);
		
		window->SetMousePressFunction([this](int32 key, int32 action, int32 mod)
		{
			this->keyEvent(key, action, mod);
			std::cout << "Key: " << key << " action: " << action << std::endl;

			if (key == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
			{
				leftButtonPressed = true;		
			}
			if (key == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE)
			{
				leftButtonPressed = false;
			}
		}
		);


		
		window->SetMouseMoveFunction([this](float64 xpos, float64 ypos)
			{
				this->MousePos(xpos, ypos);
				
				std::cout << xpos << "  :  " << ypos << std::endl;
				if (leftButtonPressed && dx < xpos)
				{
					cubenode.GetTransform()->RotY(0.01f);
				}
				else if (leftButtonPressed && dx > xpos)
				{
					cubenode.GetTransform()->RotY(-0.01f);
				}
				else if (leftButtonPressed && dy < ypos)
				{
					cubenode.GetTransform()->RotX(0.01f);
				}
				if (leftButtonPressed && dy > ypos)
				{
					cubenode.GetTransform()->RotX(-0.01f);
				}
				dx = xpos;
				dy = ypos;
			}
			
		);
		



		if (this->window->Open())
		{
			glClearColor(0.1f, 0.1f, 0.4f, 1.0f);

			glEnable(GL_DEPTH_TEST);
			glDepthFunc(GL_LESS);

			Matrix4D m;
			Matrix4D rot;
			Matrix4D rot2;
			
			Vector4D startcam(0, 0.8f, 2, 1);
			const auto mesh = std::make_shared<MeshResource>();
			const auto tex = std::make_shared<Texture>("../texture1.png");
			const auto shad = std::make_shared<ShaderResource>("../shader.glsl");
			const auto tran = std::make_shared<Transform>(m, m, m);
			const auto cam = std::make_shared<Cam>(startcam, Vector4D(0, 0, 0, 1));
			cubenode = GraphicNode(mesh, tex, shad, tran, cam);
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
		while (this->window->IsOpen())
		{

			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			cubenode.Draw();
			this->window->Update();
			this->window->SwapBuffers();
		}
	}
} // namespace Example
