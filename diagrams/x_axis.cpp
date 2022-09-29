#include "x_axis.h"

void x_axis::draw(sf::RenderTarget& target, sf::RenderStates states)const {
	sf::RectangleShape line1(sf::Vector2f(length,4));
	line1.setPosition(loc);
	line1.setFillColor(sf::Color(0, 0, 0));
	target.draw(line1);
	int start = loc.x + 0.025 * length;
	int finish =start + length * 0.95;
	
}
void x_axis::setLegnth(int a) {
	length = a;
}
void x_axis::setLoc(float x, float y) {
	loc.x = x;
	loc.y = y;
}
