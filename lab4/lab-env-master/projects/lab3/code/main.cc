//------------------------------------------------------------------------------
// main.cc
// (C) 2015-2018 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include "config.h"
#include "lab3.h"

int
main(int argc, const char** argv)
{
	Example::Lab3 app;
	if (app.Open())
	{
		app.Run();
		app.Close();
	}
	app.Exit();
	
}