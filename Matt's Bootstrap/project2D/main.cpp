#include "Application2D.h"

//--------------------------------------------------------------------------------------
// Runs the game
//
// Return:
//		Returns zero when the application is finished running.
//--------------------------------------------------------------------------------------
int main()
{
	// Creates a "new" application2D
	Application2D* pApp = new Application2D();

	// Calls the run function to load program
	pApp->run("AIE", 1280, 720, false);

	// Deletes app to prevent memory leaks
	delete pApp;

	return 0;
}