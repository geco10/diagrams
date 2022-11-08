#pragma once
#include"DrawableInNewWindow.h"
#include<SFML/Graphics.hpp>
class f_x :public DrawableInNewWindow{
	double a, b;
	sf::Vector2f loc,size;
public:
	f_x(double n, double m);
	void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
	void setLoc(double x, double y);
	void setSize(double x, double y);
private:
	void countSetings(int x, int y)override;
	double calc(double x)const;
};

