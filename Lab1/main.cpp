#include "Rectangle.cpp"
#include <iostream>

using namespace std;

int main()
{
	
	auto my_rectangle = Rectangle({ {5, 0}, {0, 5 } });
	auto div_result = my_rectangle / 5;
	cout << div_result[0];
	
	return 0;
}