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
	int fMin() {
		const std::vector<double>& arr=*data;
		int min=arr[0];
		for (int i = 1; i < arr.size(); i++) {
			if (min > arr[i])min = arr[i];
		}
		return min;
	}
};

