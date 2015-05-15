#include "Core.h"
#include "DummyScreen.h"

int main(void)
{
	DummyScreen* screen = new DummyScreen();
	Core c(screen);
	c.start();

	return 0;
}