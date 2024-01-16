#include "f_x.h"
#include<vector>

bool f_x::numCheck(double a)const
{
   return !isnan(a)&&!isinf(a);
}

void f_x::countSetings(int x, int y){
    size.x = x * 0.8;
    size.y = y * 0.8;
    loc.y = y * 0.1;
    loc.x = x * 0.1;
}


f_x::f_x(double n, double m, std::function<double(double)> func) :calc(func) {
    a = n;
    b = m;
  
}
void f_x::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    double step = (b - a) / (size.x*0.9);
    std::vector<double> data;
    for (double x = a; x < b; x+=step){
        data.push_back(calc(x));
    }
    data.push_back(calc(b));
    double ymax=-30000, ymin=30000;
    for (double i :  data)
    {
        if (!numCheck(i)) continue;
        if (i > ymax)ymax = i;
        if (i < ymin)ymin = i;
    }
    double stepy = (size.y*0.9) / (ymax - ymin);
    for (int i = 0; i < data.size(); i++)
    {
        if (!numCheck(data[i])) continue;
        sf::Vector2f location;
        location.x = loc.x + i;
        location.y = loc.y + size.y - ((data[i] - ymin) * stepy);		sf::RectangleShape line1(sf::Vector2f(size.x, 4));

        sf::CircleShape point(2);
        point.setFillColor(sf::Color::Blue);
        point.setPosition(location);
        target.draw(point);
    }

    {// x-axis
        sf::RectangleShape line1(sf::Vector2f(size.x, 4));
        line1.setPosition(loc.x, loc.y + size.y);
        line1.setFillColor(sf::Color::Black);
        target.draw(line1);
        sf::RectangleShape line2(sf::Vector2f(40, 4));
        line2.setRotation(150);
        line2.setFillColor(sf::Color::Black);
        line2.setPosition(size.x + loc.x , loc.y + 4 + size.y);
        target.draw(line2);
        sf::RectangleShape line3(sf::Vector2f(40, 4));
        line3.setRotation(210);
        line3.setFillColor(sf::Color::Black);
        line3.setPosition(size.x + loc.x, loc.y + 4 + size.y);
        target.draw(line3);
    }

    {//y-axis
        sf::RectangleShape line1(sf::Vector2f(4, 4 + size.y));
        line1.setPosition(loc.x,loc.y);
        line1.setFillColor(sf::Color::Black);
        target.draw(line1);
        sf::RectangleShape line2(sf::Vector2f(40, 4));
        line2.setRotation(60);
        line2.setFillColor(sf::Color::Black);
        line2.setPosition(loc.x + 4, loc.y + 4);
        target.draw(line2);
        sf::RectangleShape line3(sf::Vector2f(40, 4));
        line3.setRotation(120);
        line3.setFillColor(sf::Color::Black);
        line3.setPosition(loc.x + 3, loc.y + 4);
        target.draw(line3);
    }

}
void f_x::setLoc(double x, double y) {
    loc.x = x;
    loc.y = y;
}
void f_x::setSize(double x, double y) {
    size.x = x;
    size.y = y;
}