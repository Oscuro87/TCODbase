#include "DummyScreen.h"
#include <libtcod.hpp>

void DummyScreen::render() const
{
	TCODConsole::root->print(1, 1, textToShow.c_str());
	lineInput.render();
	TCODConsole::root->flush();
}

void DummyScreen::input()
{
	TCOD_key_t key;
	TCODSystem::waitForEvent(TCOD_EVENT_KEY_PRESS, &key, NULL, true);
	
	if (!lineInput.isInputFinished())
	{
		lineInput.input();
	}

	if (key.c == 'c')
	{
		transitionRequired = true;
		transitionTarget = new DummyScreen("Created screen");
	}
	else
	{
		transitionRequired = true;
		transitionTarget = NULL;
	}
}
