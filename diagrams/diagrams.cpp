#include <iostream>
#include"x_axis.h"
int main(){
	std::vector<double> arr={4,9,-6,7,-1,10};
	x_axis xa(&arr);
	xa.drawInNewindow(800, 800);
   return 0;
}