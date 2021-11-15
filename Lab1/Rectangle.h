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
	void setPoints(const point, const point);
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
	void move(const int32_t, const int32_t); 
	/*
	* \brief Overload of istream operator. Allows enter the Rectangle in input stream.
	* \param stream - input stream.
	* \param object - Rectangle object
	* \return stream
	*/
	friend istream& operator>>(istream& stream, Rectangle& object)
	{
		cout << "Enter coordinates of upper-left corner: \n";
		stream >> object.upper_left_corner.x >> object.upper_left_corner.y;
		cout << "Enter coordinates of lower-right corner: \n";
		stream >> object.lower_right_corner.x >> object.lower_right_corner.y;
		cout << endl;
	};
	/*
	* \brief Overload of ostream operator. Allows withdraw the Rectangle in output stream.
	* \param stream - output stream
	* \param object - Rectangle object
	* \return stream
	*/
	friend ostream& operator<<(ostream& stream, const Rectangle object)
	{
		stream << "( " << object.upper_left_corner.x << ", " << object.upper_left_corner.y << " )\n";
		stream << "          " << "( " << object.lower_right_corner.x << ", " << object.lower_right_corner.y << " )" << endl;
	};
};

