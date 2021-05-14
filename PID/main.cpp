
#include"PID.h"
#include"Vector.h"
#include"System.h"
#include <cstdio>
#include<unistd.h>
#include<math.h>
#include<time.h>

constexpr double P_GAIN = 0.2;
constexpr double I_GAIN = .05;
constexpr double D_GAIN = .02;
constexpr double THRESHOLD = .0001;

double Control(System1D& sys,double target, double p, double i, double d, double feedBack)
{
    double error = target - sys.mAngle;
    printf("Error : %.3lf\n", error);
    printf("Angle : %.3lf\n", sys.mAngle);
    printf("Feedback : %.3lf\n", feedBack);
    
    if (fabsf64(error) < THRESHOLD)
    {
        printf("BREAK, Control Done.\n");
        return sys.mAngle;
    }

    if (error > 0)
    {
        sys.mAngle += feedBack;
    }

    if (error < 0)
    {
        sys.mAngle -= feedBack;
    }

    if (error <= feedBack / p)
    {
        feedBack *= p;
    }
    
  //  usleep(500000);
    printf("-------------------------------\n");
    return Control(sys, target, p, i, d, feedBack);
}

double SystemUpdate(double input)
{
    static double output = 0.0;
    static const double alpha = 0.02;

    output = (0.01 * input + output) / (1.0 + alpha * 0.01);

    return output;
}

int main()
{
    System1D sys(1.333);
    
    double error = 0.000;
    double total = 0.0;
    double delta = 0.00016;
    double target = 0.0;
    sys.mAngle = 0;
    PID pid(P_GAIN, I_GAIN, D_GAIN, sys.GetMax(), 0.02, 0.01, -10.0, 10.0);
    error = abs(sys.mAngle - target);
    
    double previous = time(NULL);
    double setPoint = 1.0;
    for (float t = 0.0f; t <= 10.0f; t += 0.001f)
    {
        error = abs(setPoint - sys.mAngle);
        sys.mAngle = SystemUpdate(pid.mOut);
        
        double correction = pid.Control(error, delta, sys.mAngle);
       
        printf("%.3lf, %.3lf, %.3lf\n", sys.mAngle, setPoint, error);

    }

    printf("Result : %.3lf\n", sys.mAngle);
    



    return 0;
}