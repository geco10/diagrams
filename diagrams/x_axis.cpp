#include "x_axis.h"


void x_axis::draw(sf::RenderTarget& target, sf::RenderStates states)const {
	sf::RectangleShape line1(sf::Vector2f(length,4));
	line1.setPosition(loc);
	line1.setFillColor(sf::Color(0, 0, 0));
	target.draw(line1);
	double start = loc.x + 0.025 * length;
	double finish =start + length * 0.95;
	double k = (0.95 * length) / (fMax()-fMin());
	for (int i = 0; i < (*data).size(); ++i) {
		sf::CircleShape c(4);
		c.setFillColor(sf::Color::Red);
		c.setPosition(((( * data)[i] - fMin()) * k)+start, loc.y);
		target.draw(c);
	}
}
void x_axis::setLegnth(int a) {
	length = a;
}
void x_axis::setLoc(float x, float y) {
	loc.x = x;
	loc.y = y;
}
double x_axis::fMin()const {
	const std::vector<double>& arr = *data;
	double min = arr[0];
	for (int i = 1; i < arr.size(); i++) {
		if (min > arr[i])min = arr[i];
	}
	return min;
}
double x_axis::fMax()const {
	const std::vector<double>& arr = *data;
	double max = arr[0];
	for (int i = 1; i < arr.size(); i++) {
		if (max < arr[i])max = arr[i];
	}
	return max;
}
