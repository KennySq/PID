#include "PID.h"


// angular velocity = 85.0
// error = 85.0
// want 0.000
double PID::Control(double error, double delta, double measurement)
{
    double propotional = mKp * error;
    double integral = 0.0;
    double derivatives = 0.0;

    integral = integral + 0.5f * mKi * mSampleTime * (error + mPreviousError);
    if (integral > mLimMax)
    {
        integral = mLimMax;
    }
    else if (integral < mLimMin)
    {
        integral = mLimMin;
    }

    derivatives = -(2.0 * mKd * (measurement - mPreviousMeasurement)
        + (2.0 * mTau - mSampleTime) * derivatives)
        / (2.0 * mTau + mSampleTime);

    mOut = propotional + integral + derivatives;

    if (mOut > mLimMax)
    {
        mOut = mLimMax;
    }
    else if (mOut < mLimMin)
    {
        mOut = mLimMin;
    }

    mPreviousError = error;
    mPreviousMeasurement = measurement;

    return mOut;


}
