#ifndef PID_CONTROLLER_HPP
#define PID_CONTROLLER_HPP

#include "main.h"

// 後退差分による離散化

class Integrator
{
public:
    Integrator(float control_period);

    float Update(float error);

private:
    float control_period;
    static float error_sum = 0;
};

class Differentiator
{
public:
    Differentiator(float tf, float control_period);

    float Update(float error);

private:
    float tf;
    float control_period;
    float coeff;
    static float pre_error = 0;
    static float pre_deriv = 0;
};

class PID
{
public:
    PID(float kp, float ki, float kd, float tf, float control_period);

    float Update(float error);

private:
    float kp;
    float ki;
    float kd;
    Integrator integrator;
    Differentiator differentiator;
};
#endif //  PID_CONTROLLER_HPP