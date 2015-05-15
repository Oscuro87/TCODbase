#ifndef COREH
#define COREH

#include <libtcod.hpp>
#include "ScreenManager.h"

class Core
{
private:
	ScreenManager screenManager;

	void loop();
	void  checkTransition();

public:
	bool running;

	Core(Screen* firstScreen);
	
	void start();
};

#endif