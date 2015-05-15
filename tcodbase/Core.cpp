#include "Core.h"

void Core::loop()
{
	while (running && !TCODConsole::root->isWindowClosed() && screenManager.hasScreens())
	{
		TCODConsole::root->clear();

		screenManager.peekScreen()->render();
		screenManager.peekScreen()->input();

		checkTransition();

		TCODConsole::flush();
	}
}

void Core::checkTransition()
{
	Screen* current = screenManager.peekScreen();
	Screen* dump = 0;
	
	if (current->transitionRequired)
	{
		if (current->transitionTarget == NULL || current->destroyThisScreen)
		{
			dump = current;
			screenManager.popScreen();
		}

		if (current->transitionTarget != NULL)
			screenManager.pushScreen(current->transitionTarget);

		delete dump;
	}
}

Core::Core(Screen * firstScreen)
	: running(false)
{
	TCODConsole::root->initRoot(80, 50, "Test");
	screenManager.pushScreen(firstScreen);
}

void Core::start()
{
	running = true;
	loop();
}
