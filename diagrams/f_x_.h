#pragma once
#include"DrawableInNewWindow.h"
#include<SFML/Graphics.hpp>
class f_x_ :public DrawableInNewWindow{
	double a, b;
	sf::Vector2f loc,size;
	f_x_(double n, double m);
	void setLoc(double x, double y);
	void setSize(double x, double y);
private:
	void countSetings(int x, int y)override;
	double calc(double x);
};

