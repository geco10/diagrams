#include "f_x_.h"

void f_x_::countSetings(int x, int y){
    size.x = x * 0.8;
    size.y = y * 0.8;
    loc.y = y * 0.1;
    loc.x = x * 0.1;
}

double f_x_::calc(double x)
{
    return sqrt(x);
}

f_x_::f_x_(double n, double m) {
    a = n;
    b = m;
}
void f_x_::setLoc(double x, double y) {
    loc.x = x;
    loc.y = y;
}
void f_x_::setSize(double x, double y) {
    size.x = x;
    size.y = y;
}