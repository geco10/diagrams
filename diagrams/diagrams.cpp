#include <iostream>
#include"BarChart.h"
#include"x_axis.h"
#include"f_x.h"
 int main(){
	std::vector<double> arr={4,9,11,15,19,30};
	f_x f(-100.0, 100.0, [](double x) {
		return x*x*6-9*x/6*x*x*x;
    });
	f.drawInNewWindow(800, 800);
   return 0;
 }