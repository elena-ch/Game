#include "Column.h"
#include "Symbol.h"


Column::Column()
{
}
Column::Column(float Col, int Jump)
{
	jumps = Jump;
	columnX = Col;

	s1.SetX(columnX);
	s1.SetY(-150.0f);
	s1.SetSymbolRect(0);
	s1.Update();

	s2.SetX(columnX);
	s2.SetY(50.0f);
	s2.SetSymbolRect(150);
	s2.Update();

	s3.SetX(columnX);
	s3.SetY(250.0f);
	s3.SetSymbolRect(300);
	s3.Update();

	s4.SetX(columnX);
	s4.SetY(450.0f);
	s4.SetSymbolRect(450);
	s4.Update();

	s5.SetX(columnX);
	s5.SetY(650.0f);
	s5.SetSymbolRect(600);
	s5.Update();

}
void Column::Draw(RenderWindow& window)
{

	window.draw(s1.GetSprite());
	window.draw(s2.GetSprite());
	window.draw(s3.GetSprite());
	window.draw(s4.GetSprite());
	window.draw(s5.GetSprite());

}

void Column::standartPosition()
{
	if (jumps == 0) {
		if (upperSymbol == 1)
		{
			s1.setYPosition(-150.0f);
			s2.setYPosition(50.0f);
			s3.setYPosition(250.0f);
			s4.setYPosition(450.0f);
			s5.setYPosition(650.0f);
		}
		if (upperSymbol == 2)
		{
			s2.setYPosition(-150.0f);
			s3.setYPosition(50.0f);
			s4.setYPosition(250.0f);
			s5.setYPosition(450.0f);
			s1.setYPosition(650.0f);
		}
		if (upperSymbol == 3)
		{
			s3.setYPosition(-150.0f);
			s4.setYPosition(50.0f);
			s5.setYPosition(250.0f);
			s1.setYPosition(450.0f);
			s2.setYPosition(650.0f);
		}
		if (upperSymbol == 4)
		{
			s4.setYPosition(-150.0f);
			s5.setYPosition(50.0f);
			s1.setYPosition(250.0f);
			s2.setYPosition(450.0f);
			s3.setYPosition(650.0f);
		}
		if (upperSymbol == 5)
		{
			s5.setYPosition(-150.0f);
			s1.setYPosition(50.0f);
			s2.setYPosition(250.0f);
			s3.setYPosition(450.0f);
			s4.setYPosition(650.0f);
		}

	}

}

void Column::Motion(float Time, float Speed)
{
	time = Time;
	speed = Speed;
	float step = Time * speed;
	if (jumps > 0) {



		if (s1.getYPosition() + step >= lowerBorder)
		{
			s1.setYPosition(upBorder + step);
			s1.randomSprite();
			s2.setYPosition(s2.getYPosition() + step);
			s3.setYPosition(s3.getYPosition() + step);
			s4.setYPosition(s4.getYPosition() + step);
			s5.setYPosition(s5.getYPosition() + step);
			jumps--;
			upperSymbol = 1;

		}
		else
			if (s2.getYPosition() + step >= lowerBorder)
			{
				s2.setYPosition(upBorder + step);
				s2.randomSprite();
				s1.setYPosition(s1.getYPosition() + step);
				s3.setYPosition(s3.getYPosition() + step);
				s4.setYPosition(s4.getYPosition() + step);
				s5.setYPosition(s5.getYPosition() + step);
				jumps--;
				upperSymbol = 2;
			}
			else
				if (s3.getYPosition() + step >= lowerBorder)
				{
					s3.setYPosition(upBorder + step);
					s3.randomSprite();
					s1.setYPosition(s1.getYPosition() + step);
					s2.setYPosition(s2.getYPosition() + step);
					s4.setYPosition(s4.getYPosition() + step);
					s5.setYPosition(s5.getYPosition() + step);
					jumps--;
					upperSymbol = 3;
				}
				else
					if (s4.getYPosition() + step >= lowerBorder)
					{
						s4.setYPosition(upBorder + step);
						s4.randomSprite();
						s1.setYPosition(s1.getYPosition() + step);
						s2.setYPosition(s2.getYPosition() + step);
						s3.setYPosition(s3.getYPosition() + step);
						s5.setYPosition(s5.getYPosition() + step);
						jumps--;
						upperSymbol = 4;
					}
					else
						if (s5.getYPosition() + step >= lowerBorder)
						{
							s5.setYPosition(upBorder + step);
							s5.randomSprite();
							s1.setYPosition(s1.getYPosition() + step);
							s2.setYPosition(s2.getYPosition() + step);
							s3.setYPosition(s3.getYPosition() + step);
							s4.setYPosition(s4.getYPosition() + step);
							jumps--;
							upperSymbol = 5;
						}
						else {

							s1.setYPosition(s1.getYPosition() + step);
							s2.setYPosition(s2.getYPosition() + step);
							s3.setYPosition(s3.getYPosition() + step);
							s4.setYPosition(s4.getYPosition() + step);
							s5.setYPosition(s5.getYPosition() + step);

						}


	}
	Column::standartPosition();
}

int Column::GetJumps()
{
	return jumps;
}

void Column::ResetJumps(int Jump)
{
	jumps = Jump;
}


