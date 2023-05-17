#pragma once
#include "GameBase.h"
#include <iostream>
#include <string>

class Game : public GameBase
{
public:

	Game() { }

	void start() override;

	std::string getNumber() override { return number; }

private:
	std::string number = "";

	int randomNumber();

	std::string allegedNumber(std::string);
};

