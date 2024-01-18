#pragma once
#include<SFML/Graphics.hpp>
class Axis : public sf::Drawable
{
	sf::Vector2f loc, size;
	sf::Color col;
public:
	Axis(sf::Vector2f loc,sf::Vector2f size,sf::Color c);
	void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
};

