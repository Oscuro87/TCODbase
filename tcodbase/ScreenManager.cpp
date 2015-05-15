#include "ScreenManager.h"

ScreenManager::ScreenManager()
{}

ScreenManager::~ScreenManager()
{
	for (int i = screens.size() - 1; i >= 0; i--)
	{
		delete screens.top();
		screens.pop();
	}
}

void ScreenManager::pushScreen(Screen *& newScreen)
{
	screens.push(newScreen);
}

void ScreenManager::popScreen()
{
	screens.pop();
}

Screen* ScreenManager::peekScreen()
{
	return screens.top();
}

bool ScreenManager::hasScreens()
{
	return screens.size() > 0;
}
