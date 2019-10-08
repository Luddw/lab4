#pragma once
//------------------------------------------------------------------------------
/**
	Application class used for example application.
	
	(C) 2015-2018 Individual contributors, see AUTHORS file
*/
//------------------------------------------------------------------------------
#include "core/app.h"
#include "render/window.h"
#include "graphicnode.h"


namespace Example
{
class Lab3 : public Core::App
{
public:
	/// constructor
	Lab3();
	/// destructor
	~Lab3();
	void keyEvent(int key, int action, int modifier);
	void MousePos(float xpos, float ypos);

	/// open app
	bool Open();
	/// run app
	void Run();
private:
	bool leftButtonPressed = false;
	bool ismoving = false;
	float dx = 0;
	float dy = 0;
	GraphicNode cubenode;
	Display::Window* window;
};
} // namespace Example