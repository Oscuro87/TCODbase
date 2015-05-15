#ifndef LINEINPUTH
#define LINEINPUTH

#include <string>
#include <libtcod.hpp>

class LineInput
{
protected:
	std::string buffer;
	std::string writeMark;
	bool inputFinished;

public:
	LineInput(std::string writeMark = "");

	void input();
	void render() const;
	void reset();
	const char* getText() const;
	bool isInputFinished() const;
};

#endif
