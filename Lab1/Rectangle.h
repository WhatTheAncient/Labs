#pragma once
#include <cstdint>
#include <string>
class Rectangle
{
	struct point { int32_t x; int32_t y; };
	point upper_left_corner;
	point lower_right_corner;
public:
	Rectangle()
	{
		upper_left_corner = { 0, 0 };
		lower_right_corner = { 0, 0 };
	};
	Rectangle(const point point_1, const point point_2) : Rectangle()
	{
		upper_left_corner = point_1;
		lower_right_corner = point_2;
	};
	Rectangle(const Rectangle& rectangle) : Rectangle()
	{
		upper_left_corner = rectangle.upper_left_corner;
		lower_right_corner = rectangle.lower_right_corner;
	};
	point* getPoints();
	void setPoints();
	int32_t* lengths();
	int32_t square();
	void move(int32_t x, int32_t y);
};

