#pragma once
#include <iostream> 
#include <SFML/Graphics.hpp>

using namespace sf;

class Symbol
{
public:

	Symbol();
	Symbol(float X, float Y, float Rect);

	void SetX(float X);

	void SetY(float Y);

	void SetSymbolRect(float Rect);

	void Update();

	void setYPosition(float Y);

	float getYPosition() const;

	void randomSprite();

	Sprite GetSprite();

private:

	Image image;
	Texture texture;
	Sprite sprite;

	float arrTextureRectLeft[5] = { 0, 150, 300, 450, 600 };
	float symbolX, symbolY, textureRectLeft, speed;

};

