#include "BarChart.h"
#include<cmath>
void BarChart::setSize(float x, float y)
{
	size.x = x;
	size.y = y;
}
void BarChart::setBarsColor(int r, int g, int b, int a) {
	barsColor.r = r;
	barsColor.g = g;
	barsColor.b = b;
	barsColor.a = a;
}
BarChart::BarChart(const std::vector<double>* arr){
	makeBars(arr);
	barsColor = sf::Color::Blue;
}
void BarChart::drawInNewindow(int x, int y, bool sets) {
	if (sets) {
		countSetings(x, y);
	}
	sf::RenderWindow window(sf::VideoMode(x, y), "SFML works!");
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear(sf::Color(225, 225, 225));
		window.draw(*this);
		window.display();
	}
}
void BarChart::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
	double k = (size.y*0.9)/maxBar();
	float width = (size.x * 0.9) / bars.size();
	for (int i = 0; i < bars.size(); ++i) {
		sf::RectangleShape bar(sf::Vector2f(width, bars[i].second*k));
		bar.setFillColor(barsColor);
		bar.setOutlineColor(sf::Color(255-barsColor.r, 255 - barsColor.g,255 - barsColor.b,barsColor.a));
		bar.setOutlineThickness(2);
		target.draw(bar);
	}
}

int BarChart::mRet(int n)
{
	return 1+3.3221*log(n);
}
void BarChart::countSetings(int x, int y) {
	size.x = x * 0.8;
	size.y = y * 0.8;
	loc.y = y / 2;
	loc.x = x * 0.1;
}

double BarChart::fStep(double min,double max,int n){
	double range = max - min;
	return range / mRet(n);
}

void BarChart::makeBars(const std::vector<double>* arr){
	int curr = 0;
	double step = fStep((*arr)[0],(*arr)[arr->size()-1],(arr->size());
	for (int i = 0; i < mRet(arr->size()); ++i) {
		double l = (*arr)[0] + step * i;
		double r = l + step;
		int t = 0;
		for (; r > (*arr)[curr];++curr)++t;
		std::pair <double, int> a={l+step/2,t};
		bars.push_back(a);
	}
}

int BarChart::maxBar()const
{
	int max = 0;
	for (auto el : bars) {
		if (el.second > max)max = el.second;
	}
	return max;
}


