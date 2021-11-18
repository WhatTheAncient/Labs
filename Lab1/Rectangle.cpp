#include "Rectangle.h"

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

double_t* Rectangle::getSides()
{
	double_t side_1 = this->lower_right_corner.x - this->upper_left_corner.x;
	double_t side_2 = this->upper_left_corner.y - this->lower_right_corner.y;

	double_t sides[2] = { side_1, side_2 };
	return sides;
}

double_t Rectangle::getSquare()
{
	double* sides = this->getSides();

	return sides[0] * sides[1];
}

void Rectangle::makeMove(const double _x, const double _y)
{
	this->lower_right_corner.x += _x;
	this->lower_right_corner.y += _y;
	this->upper_left_corner.x += _x;
	this->upper_left_corner.y += _y;
}

Rectangle Rectangle::operator*(double_t multiplier)
{
	Rectangle object = *this;
	if (multiplier >= 0)
	{
		object.upper_left_corner.x *= sqrt(multiplier);
		object.upper_left_corner.y *= sqrt(multiplier);
		object.lower_right_corner.x *= sqrt(multiplier);
		object.lower_right_corner.y *= sqrt(multiplier);
	}
	else
	{
		multiplier = pow(abs(multiplier), -1);
		object.upper_left_corner.x *= sqrt(multiplier);
		object.upper_left_corner.y *= sqrt(multiplier);
		object.lower_right_corner.x *= sqrt(multiplier);
		object.lower_right_corner.y *= sqrt(multiplier);
	}
	return object;
}

Rectangle* Rectangle::operator/(const int32_t divider)
{
	if (divider >= 0)
	{
		const size_t size = divider;
		Rectangle* div_result = new Rectangle[size];
		double_t length = this->getSides()[0];
		for (size_t i = 0; i < size; i++)
		{
			Rectangle rect;

			rect.upper_left_corner.x = this->upper_left_corner.x + length / size * i;
			rect.upper_left_corner.y = this->upper_left_corner.y;
			rect.lower_right_corner.x = this->upper_left_corner.x + length / size * (i + 1);
			rect.lower_right_corner.y = this->lower_right_corner.y;
			div_result[i] = rect;
		};
		return div_result;
	}
}


istream& operator>>(istream& stream, Rectangle& object)
{
	cout << "Enter coordinates of upper-left corner: \n";
	stream >> object.upper_left_corner.x >> object.upper_left_corner.y;
	cout << "Enter coordinates of lower-right corner: \n";
	stream >> object.lower_right_corner.x >> object.lower_right_corner.y;
	cout << endl;
	return stream;
};
ostream& operator<<(ostream& stream, const Rectangle& object)
{
	stream.precision(2);
	stream << "( " << object.upper_left_corner.x << ", " << object.upper_left_corner.y << " )\n";
	stream << "          " << "( " << object.lower_right_corner.x << ", " << object.lower_right_corner.y << " )" << endl;
	return stream;
};