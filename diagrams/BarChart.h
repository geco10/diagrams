#pragma once
#include<utility>
#include<vector>
#include<SFML/Graphics.hpp>
class BarChart :public sf::Drawable{
	std::vector<std::pair<double, int>> bars;
	sf::Vector2f size;
	sf::Vector2f loc;
	sf::Color barsColor;
	double width;
public:
	void setSize(float x, float y);
	void drawInNewindow(int x, int y, bool sets = true);
	void setBarsColor(int r, int g, int b, int a = 255);
	BarChart(const std::vector<double>* arr);
	void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
private:
	int mRet(int n);
	void countSetings(int x, int y);//false-custom setting
	double fStep(double min,double max,int n);
	void makeBars(const std::vector<double>* arr);
	int maxBar()const;
};

