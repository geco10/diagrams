#include "f_x.h"
#include<vector>

void f_x::countSetings(int x, int y){
    size.x = x * 0.8;
    size.y = y * 0.8;
    loc.y = y * 0.1;
    loc.x = x * 0.1;
}

double f_x::calc(double x)const
{
    return sqrt(x);
}

f_x::f_x(double n, double m) {
    a = n;
    b = m;
}
void f_x::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    double step = (b - a) / size.x;
    std::vector<double> data;
    for (double x = a; x < b; x+=step){
        data.push_back(calc(x));
    }
    data.push_back(calc(b));
    double ymax=data[0], ymin=data[0];
    for (double i :  data)
    {
        if (i > ymax)ymax = i;
        else
            if (i < ymin)ymin = i;
    }
    double stepy = (size.y) / (ymax - ymin);
    for (int i = 0; i < data.size(); i++)
    {
        sf::Vector2f location;
        location.x = loc.x + i;
        location.y= loc.y + size.y - ((data[i]-ymin) * stepy);

        sf::CircleShape point(2);
        point.setFillColor(sf::Color::Blue);
        point.setPosition(location);
        target.draw(point);
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