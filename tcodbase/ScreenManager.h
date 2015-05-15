#ifndef SCREENMANAGERH
#define SCREENMANAGERH

#include <stack>
#include "Screen.h"

class ScreenManager
{
private:
	std::stack<Screen*> screens;

public:
	ScreenManager();
	~ScreenManager();

	void pushScreen(Screen *&newScreen);
	void popScreen();
	Screen* peekScreen();

	bool hasScreens();
};

#endif
