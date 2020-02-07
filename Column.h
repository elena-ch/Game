#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Symbol.h"

using namespace sf;


class Column
{

public:

	Column();
	Column(float Col, int Jump);

	void Draw(RenderWindow& window);

	int GetJumps();
	void ResetJumps(int Jump);
	void Motion(float Time, float Speed);

private:

	Symbol s1;
	Symbol s2;
	Symbol s3;
	Symbol s4;
	Symbol s5;

	int jumps = 0;

	float columnX = 0;
	float time = 0;
	float speed = 0;
	float upBorder = -150.0f;
	float lowerBorder = 850.0f;
	int upperSymbol = 1;

	void standartPosition();
};
