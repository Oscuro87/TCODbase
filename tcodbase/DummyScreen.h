#ifndef DUMMYSCREENH
#define DUMMYSCREENH

#include <string>
#include "LineInput.h"
#include "Screen.h"

struct DummyScreen : public Screen
{
private:
	std::string textToShow;
	LineInput lineInput;

public:
	DummyScreen(std::string textToShow="Test")
		: textToShow(textToShow)
	{}
	
	void render() const;
	void input();
};

#endif