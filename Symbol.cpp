#include "Symbol.h"


Symbol::Symbol()
{
}

Symbol::Symbol(float X, float Y, float Rect)
{

	speed = 0;
	image.loadFromFile("Images/sym.png");
	texture.loadFromImage(image);
	sprite.setTexture(texture);

	symbolX = X;
	symbolY = Y;
	textureRectLeft = Rect;

	sprite.setTextureRect(IntRect(textureRectLeft, 0, 150, 200));
	sprite.setPosition(symbolX, symbolY);
}

void Symbol::SetX(float X) { symbolX = X; }
void Symbol::SetY(float Y) { symbolY = Y; }
void Symbol::SetSymbolRect(float Rect) { textureRectLeft = Rect; }

void Symbol::Update()
{

	speed = 0;
	image.loadFromFile("Images/sym2.png");
	texture.loadFromImage(image);
	sprite.setTexture(texture);

	sprite.setTextureRect(IntRect(textureRectLeft, 0, 150, 200));
	sprite.setPosition(symbolX, symbolY);
}


void Symbol::setYPosition(float Y)
{
	symbolY = Y;
	sprite.setPosition(symbolX, Y);
}

float Symbol::getYPosition() const
{
	return symbolY;
}

void Symbol::randomSprite()
{
	sprite.setTextureRect(IntRect(arrTextureRectLeft[rand() % 5], 0, 150, 200));
}

Sprite Symbol::GetSprite()
{
	return sprite;
}
