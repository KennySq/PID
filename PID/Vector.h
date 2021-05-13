#pragma once
#include<string>
#include<cstdio>
struct Vector
{
public:
    Vector(double x, double y) : mX(x), mY(y) { }
    ~Vector() {}

    Vector& operator+=(const Vector& rhs);
    Vector operator+(const Vector& rhs);

    Vector operator-(const Vector& rhs);
    Vector& operator-=(const Vector& rhs);

    const char* ToString();
private:
    double mX;
    double mY;

};