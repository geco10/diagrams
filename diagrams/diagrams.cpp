#include <iostream>
#include"BarChart.h"
#include"x_axis.h"
int main(){
	std::vector<double> arr={4,9,11,15,19,30};
	BarChart bar(&arr);
	bar.drawInNewWindow(800, 800);
   return 0;
}