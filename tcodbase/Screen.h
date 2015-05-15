#ifndef SCREENH
#define SCREENH

struct Screen
{
public:
	bool transitionRequired;
	bool destroyThisScreen;
	Screen *transitionTarget;

	Screen()
		: transitionRequired(false), destroyThisScreen(false), transitionTarget(0)
	{}
	virtual ~Screen() {};

	virtual void render() const = 0;
	virtual void input() = 0;
};

#endif