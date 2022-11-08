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
    double t = b-a;
    double t1 = size.y * 0.95;
    double step = t / t1;
    std::vector <double>y;
    for (double x = a; x <= b; x+=step){
        y.push_back(calc(x));
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