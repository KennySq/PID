#pragma once
#include"Vector.h"
class PID
{	
public:
	PID(double pg, double ig, double dg, double seed, double tau, double sampleTime, double limmin, double limmax)
		: mKp(pg), mKi(ig), mKd(dg), mFeedback(seed), mTau(tau), mSampleTime(sampleTime), mLimMin(limmin), mLimMax(limmax)
	{ }
	~PID() {}
	double Control(double error, double delta, double measurement);
	double mOut = 0.0;

private:
	double mKp;
	double mKi;
	double mKd;

	double mFeedback;
	double mPreviousError;

	double mPreviousMeasurement;

	double mThreshold;

	double mLimMin;
	double mLimMax;

	double mTau;
	double mSampleTime;
};

