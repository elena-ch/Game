#include <SFML/Graphics.hpp>
#include "Symbol.h"
#include <iostream>
#include <ctime>

#include <Windows.h>
#include <conio.h>
#include <stdio.h>
#include "Column.h"
#include "Gui.h"

using namespace sf;


Column Column1(40, 0);
Column Column2(215, 0);
Column Column3(390, 0);
Column Column4(565, 0);
Column Column5(740, 0);

Gui gui;



bool run = false;

void Play(float Time)
{

	if (Column1.GetJumps() > 1 && Column1.GetJumps() < 15)
	{
		Column1.Motion(Time, 1);
	}
	else
		Column1.Motion(Time, 0.6f);


	if (Column2.GetJumps() > 1 && Column2.GetJumps() < 20)
	{
		Column2.Motion(Time, 1);
	}
	else
		Column2.Motion(Time, 0.6f);


	if (Column3.GetJumps() > 1 && Column3.GetJumps() < 25)
	{
		Column3.Motion(Time, 1);
	}
	else
		Column3.Motion(Time, 0.6f);


	if (Column4.GetJumps() > 1 && Column4.GetJumps() < 30)
	{
		Column4.Motion(Time, 1);
	}
	else
		Column4.Motion(Time, 0.6f);


	if (Column5.GetJumps() > 1 && Column5.GetJumps() < 35)
	{
		Column5.Motion(Time, 1);
	}
	else
		Column5.Motion(Time, 0.6f);


}

void Reset()
{
	Column1.ResetJumps(15);
	Column2.ResetJumps(20);
	Column3.ResetJumps(25);
	Column4.ResetJumps(30);
	Column5.ResetJumps(35);
}

void Stop()
{
	if (Column1.GetJumps() != 0)
		Column1.ResetJumps(2);
	if (Column2.GetJumps() != 0)
		Column2.ResetJumps(2);
	if (Column3.GetJumps() != 0)
		Column3.ResetJumps(3);
	if (Column4.GetJumps() != 0)
		Column4.ResetJumps(4);
	if (Column5.GetJumps() != 0)
		Column5.ResetJumps(5);
}


int main()
{
	RenderWindow window(VideoMode(1280, 720), "Slot Machine", Style::Close | Style::Titlebar);

	Image fonImage;
	fonImage.loadFromFile("Images/fon.png");

	Texture fonTexture;
	fonTexture.loadFromImage(fonImage);

	Sprite fonSprite;
	fonSprite.setTexture(fonTexture);
	fonSprite.setPosition(0, 0);

	Image bgImage;
	bgImage.loadFromFile("Images/bg.png");

	Texture bgTexture;
	bgTexture.loadFromImage(bgImage);

	Sprite bgSprite;
	bgSprite.setTexture(bgTexture);
	bgSprite.setPosition(0, 0);

	float currentFrame = 0;//хранит текущий кадр
	Clock clock;



	while (window.isOpen())
	{

		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 750;

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(Color(255, 255, 255, 0));

		window.draw(bgSprite);

		Column1.Draw(window);
		Column2.Draw(window);
		Column3.Draw(window);
		Column4.Draw(window);
		Column5.Draw(window);

		window.draw(fonSprite);

		gui.DrawButtons(window);


		if (event.type == event.MouseButtonPressed && event.mouseButton.button == Mouse::Left)  //если отжата левая клавиша
		{
			switch (gui.Buttons(window))
			{
			case 1:

				run = true;
				if (Column5.GetJumps() == 0)
					Reset();

				break;

			case 2:

				Stop();

				break;

			default:

				break;
			}
		}


		if ((run == true) && (Column5.GetJumps() >= 0))
		{
			Play(time);

			if (Column5.GetJumps() == 0)
			{
				run = false;
			}


		}

		window.display();
	}

	return 0;
}





