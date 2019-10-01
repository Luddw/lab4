#pragma once
//------------------------------------------------------------------------------
/**
	Application class used for example application.
	
	(C) 2015-2018 Individual contributors, see AUTHORS file
*/
//------------------------------------------------------------------------------
#include "core/app.h"
#include "render/window.h"
#include "texture.h"
#include "meshresource.h"
#include "shaderresource.h"

namespace Example
{
class Lab3 : public Core::App
{
public:
	/// constructor
	Lab3();
	/// destructor
	~Lab3();

	/// open app
	bool Open();
	/// run app
	void Run();
private:

	
	MeshResource mesh;
	
	Display::Window* window;
};
} // namespace Example