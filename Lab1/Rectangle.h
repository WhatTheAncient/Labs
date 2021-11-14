#pragma once
#include <cstdint>
#include <string>

struct point { int32_t x; int32_t y; };

class Rectangle
{
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
	/*
	* \brief Return array of Rectangle private fields.
	*		 1st element - upper_left_corner,
	*		 2nd element - lower_right_corner.
	*/
	point* getPoints();
	/*
	* \brief Allows change Rectangle private fields.
	*		 1st pair of numbers - coordinates of upper_left_corner,
	*		 2nd pair of numbers - coordinates of lower_right_corner.
	*/
	void setPoints();
	/*
	* \brief Calculates the length of sides.
	* \return Array of numbers, where 1st number
	*		  is length of side which parallel Ox;
	*		  2nd number is length of side which parallel Oy.
	*/
	int32_t* getSides();
	/*
	* \brief Calculates a square of Rectangle.
	* \return Square of Rectangle
	*/
	int32_t getSquare();
	/*
	* \brief Moves Rectangle on the plane.
	* \param x - moving along the x-axis.
	* \param y - moving along the y-axis.
	*/
	void move(int32_t x, int32_t y);
};

