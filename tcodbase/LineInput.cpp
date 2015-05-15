#include "LineInput.h"

LineInput::LineInput(std::string writeMark)
	: buffer(""), inputFinished(false), writeMark(writeMark)
{}

void LineInput::input()
{
	TCOD_key_t key;
	TCODSystem::waitForEvent(TCOD_EVENT_KEY_PRESS, &key, NULL, true);

	if (key.vk == TCODK_ENTER)
	{
		inputFinished = true;
	}
	else if (key.vk == TCODK_BACKSPACE)
	{
		if(buffer.size() > 0)
			buffer.pop_back();
	}
	else if (key.vk == TCODK_SHIFT || key.vk == TCODK_ALT || key.vk == TCODK_CONTROL);
	else if (key.vk == TCODK_CHAR)
	{
		buffer.push_back(key.c);
	}
}

void LineInput::render() const
{
	TCODConsole::root->print(0, TCODConsole::root->getHeight() - 1, "%s", writeMark.c_str());
	TCODConsole::root->print(writeMark.size(), TCODConsole::root->getHeight() - 1, "%s", buffer.c_str());
}

void LineInput::reset()
{
	inputFinished = false;
	buffer = std::string("");
}

const char * LineInput::getText() const
{
	return buffer.c_str();
}

bool LineInput::isInputFinished() const
{
	return inputFinished;
}
