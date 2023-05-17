#pragma once
#include <string>

class GameBase
{
public:
	virtual void start() = 0;

	virtual std::string getNumber() = 0;
};

