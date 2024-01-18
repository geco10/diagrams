#include "Axis.h"

Axis::Axis(sf::Vector2f loc, sf::Vector2f size,sf::Color c)
{
	this->loc = loc;
	this->size = size;
    col = c;

}

void Axis::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    {// x-axis
        sf::RectangleShape line1(sf::Vector2f(size.x, 4));
        line1.setPosition(loc.x, loc.y + size.y);
        line1.setFillColor(col);
        target.draw(line1);
        sf::RectangleShape line2(sf::Vector2f(40, 4));
        line2.setRotation(150);
        line2.setFillColor(col);
        line2.setPosition(size.x + loc.x, loc.y + 4 + size.y);
        target.draw(line2);
        sf::RectangleShape line3(sf::Vector2f(40, 4));
        line3.setRotation(210);
        line3.setFillColor(col);
        line3.setPosition(size.x + loc.x, loc.y + 4 + size.y);
        target.draw(line3);
    }

    {//y-axis
        sf::RectangleShape line1(sf::Vector2f(4, 4 + size.y));
        line1.setPosition(loc.x, loc.y);
        line1.setFillColor(col);
        target.draw(line1);
        sf::RectangleShape line2(sf::Vector2f(40, 4));
        line2.setRotation(60);
        line2.setFillColor(col);
        line2.setPosition(loc.x + 4, loc.y + 4);
        target.draw(line2);
        sf::RectangleShape line3(sf::Vector2f(40, 4));
        line3.setRotation(120);
        line3.setFillColor(col);
        line3.setPosition(loc.x + 3, loc.y + 4);
        target.draw(line3);
    }
}
