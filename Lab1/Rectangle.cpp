#include "Rectangle.h"
#include <iostream>
using namespace std;

point* Rectangle::getPoints()
{
	const Rectangle rectangle = *this;
	point points[2] = { rectangle.upper_left_corner, rectangle.lower_right_corner };
	
	return points;
}

void Rectangle::setPoints(const point point_1, const point point_2)
{	
	this->upper_left_corner = point_1;
	this->lower_right_corner = point_2;
}

int32_t* Rectangle::getSides()
{
	int32_t side_1 = this->lower_right_corner.x - this->upper_left_corner.x;
	int32_t side_2 = this->upper_left_corner.y - this->lower_right_corner.y;

	int32_t sides[2] = { side_1, side_2 };
	return sides;
}

int32_t Rectangle::getSquare()
{
	int32_t* sides = this->getSides();

	return sides[0] * sides[1];
}

void Rectangle::move(const int32_t _x, const int32_t _y)
{
	this->lower_right_corner.x += _x;
	this->lower_right_corner.y += _y;
	this->upper_left_corner.x += _x;
	this->upper_left_corner.y += _y;
}
