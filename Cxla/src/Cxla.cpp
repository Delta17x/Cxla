// Mat++.cpp : Defines the entry point for the application.
//

#include "../include/Cxla.h"
#include <iostream>

using namespace cxla;

int main()
{
	vec<float, 3> v = { 100000, 2, 3 };
	vec<float, 3> v2 = { 2, 3, 4 };

	vec<float, 3> c = cross(v, v2);
	std::cout << (std::string)v;
	//std::cout << c.Data(0) << " " << c.Data(1) << " " << c.Data(2) << "\n";
	

	return 0;
}
