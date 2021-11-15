#include "Rectangle.h"
#include <iostream>

using namespace std;

int main()
{
	
	auto my_rectangle = Rectangle({ {5, 0}, {0, 5 } });
	cout << my_rectangle.getSquare();
	
	return 0;
}