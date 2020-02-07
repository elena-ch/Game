#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Gui
{

private:

	Image imageStart;
	Image imageStop;
	Texture buttonStartTexture;
	Texture buttonStopTexture;
	Sprite buttonStart;
	Sprite buttonStop;

public:

	int menuNum = 0;
	Gui();
	int Buttons(RenderWindow& window);
	Sprite GetbuttonStart();
	Sprite GetbuttonStop();
	void DrawButtons(RenderWindow& window);

};

