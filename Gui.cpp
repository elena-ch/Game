#include "Gui.h"
#include "Column.h"
#include <SFML/Graphics.hpp>
using namespace sf;


Gui::Gui()
{
	//Texture menuTexture1, menuTexture2;
	imageStart.loadFromFile("Images/start.png");
	buttonStartTexture.loadFromImage(imageStart);
	buttonStart.setTexture(buttonStartTexture);

	imageStop.loadFromFile("Images/stop.png");
	buttonStopTexture.loadFromImage(imageStop);
	buttonStop.setTexture(buttonStopTexture);

	buttonStart.setPosition(920, 70);
	buttonStop.setPosition(920, 520);

}


int Gui::Buttons(RenderWindow& window)
{
	menuNum = 0;

	if (IntRect(920, 70, 300, 119).contains(Mouse::getPosition(window)))
	{
		buttonStart.setColor(Color::Red);
		menuNum = 1;
	}

	if (IntRect(920, 520, 300, 119).contains(Mouse::getPosition(window)))
	{
		buttonStop.setColor(Color::Red);
		menuNum = 2;
	}

	return menuNum;
}

Sprite Gui::GetbuttonStart()
{
	return buttonStart;
}

Sprite Gui::GetbuttonStop()
{
	return buttonStop;
}

void Gui::DrawButtons(RenderWindow& window)
{
	window.draw(buttonStart);
	window.draw(buttonStop);
	buttonStart.setColor(Color::White);
	buttonStop.setColor(Color::White);

}


