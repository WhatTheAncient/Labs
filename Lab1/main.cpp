#include "Rectangle.h"
#include <iostream>

int main()
{
	
	auto my_rectangle = Rectangle({ {-2, 2}, {2, -2} });
	auto div_result = my_rectangle /3;
	for (size_t i = 0; i < 3; i++)
		cout << div_result[i];
	cout << my_rectangle * 4;
	return 0;
}