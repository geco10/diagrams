#pragma once
#include<utility>
#include<vector>
#include<SFML/Graphics.hpp>
class BarChart{
	std::vector<std::pair<double, int>> bars;
	double width;
public:
	BarChart(const std::vector<double>* arr);
	void draw(sf::RenderTarget& target, sf::RenderStates states);
};

