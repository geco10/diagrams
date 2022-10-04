#pragma once
#include<SFML/Graphics.hpp>
class x_axis :public sf::Drawable
{
	sf::Vector2f loc;
	int length;
	const std::vector<double>* data;
public:
	x_axis(const std::vector<double>* arr) {
		data = arr;
	}
	void setLoc(float x,float y);
	void setLegnth(int a);
	void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
private:
	double fMin()const;
	double fMax()const;
};
