#include"Vector.h"

Vector& Vector::operator+=(const Vector& rhs)
{
	mX += rhs.mX;
	mY += rhs.mY;

	return *this;
}

Vector Vector::operator+(const Vector& rhs)
{
	double x = mX + rhs.mX;
	double y = mY + rhs.mY;
	
	return Vector(x, y);
}

Vector Vector::operator-(const Vector& rhs)
{
	double x = mX - rhs.mX;
	double y = mY - rhs.mY;

	return Vector(x, y);

}

Vector& Vector::operator-=(const Vector& rhs)
{
	mX -= rhs.mX;
	mY -= rhs.mY;

	return *this;
}

const char* Vector::ToString()
{
	std::string str;

		
	str = "(" +  std::to_string(mX) + ", " + std::to_string(mY) + ")";
	
	char* raw = new char[str.size() + 1];

	std::copy(str.begin(), str.end(), raw);

	return raw;
}
