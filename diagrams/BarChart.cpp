#include "BarChart.h"

BarChart::BarChart(const std::vector<double>* arr){
	makeBars(arr);
}

void BarChart::draw(sf::RenderTarget& target, sf::RenderStates states)
{
	for (int i = 0; i < bars.size(); ++i) {
		sf::RectangleShape bar(bars[i].first, bars[i].second);
		
	}
}

int BarChart::mRet()
{
	return 13;
}

double BarChart::fStep(double min,double max){
	double range = max - min;
	return range / mRet();
}

void BarChart::makeBars(const std::vector<double>* arr){
	int curr=0;
	double step = fStep((* arr)[0], (* arr)[arr->size()]);
	for (int i = 0; i < mRet(); i++) {
		double l = (*arr)[0] + step * i;
		double r = l + step;
		int j;
		for (j = curr; (*arr)[j] < r; ++j, ++curr);
		std::pair<double, int> data;
		data.first = l+step/2;
		data.second = j - curr;
		curr = j;
	}
}
