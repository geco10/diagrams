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
    Axis ax(loc, size, sf::Color::Black);
    ax.draw(target,states);
}
void f_x::setSize(double x, double y) {
    size.x = x;
    size.y = y;
}