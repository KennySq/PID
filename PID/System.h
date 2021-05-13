#pragma once
#include"Vector.h"
class System1D
{
public:
	System1D(double maximum) : mMax(maximum) { }
	~System1D() {}

	double GetMax() const { return mMax; }
//	double GetAngle() const { return mAngle; } // why is this exists?

	double mAngle;

private:

	double mInput;
	double mMax;


};

class System2D
{
	System2D(double maximum) : mMax(maximum) { }
	~System2D() {}

	double GetMax() const { return mMax; }
	//	double GetAngle() const { return mAngle; } // why is this exists?

	double mAngle;

private:

	double mInput;
	double mMax;
};
