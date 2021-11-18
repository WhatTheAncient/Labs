#pragma once
#include <cstdint>
#include <string>
#include <iostream>
using namespace std;

struct point { double_t x; double_t y; };

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
	void setPoints(const point, const point);
	/*
	* \brief Calculates the length of sides.
	* \return Array of numbers, where 1st number
	*		  is length of side which parallel Ox;
	*		  2nd number is length of side which parallel Oy.
	*/
	double_t* getSides();
	/*
	* \brief Calculates a square of Rectangle.
	* \return Square of Rectangle
	*/
	double_t getSquare();
	/*
	* \brief Moves Rectangle on the plane.
	* \param x - moving along the x-axis.
	* \param y - moving along the y-axis.
	*/
	void makeMove(const double_t, const double_t); 
	/*
	* \brief Overload of istream operator. Allows enter the Rectangle in input stream.
	* \param stream - input stream.
	* \param object - Rectangle object
	* \return stream
	*/
	friend istream& operator>>(istream& stream, Rectangle& object);
	/*
	* \brief Overload of ostream operator. Allows withdraw the Rectangle in output stream.
	* \param stream - output stream
	* \param object - Rectangle object
	* \return stream
	*/
	friend ostream& operator<<(ostream& stream, const Rectangle& object);
	/*
	* \brief Overload of multiply operator which allows multiply Rectangle on number.
	* \param multiplier - multiplier (double)
	* \return Rectangle with changed square, but same center.
	*/
	Rectangle operator*(double_t);
	Rectangle* operator/(const int32_t);
};

