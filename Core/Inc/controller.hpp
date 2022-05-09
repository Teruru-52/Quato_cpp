#ifndef CONTROLLER_HPP_
#define CONTROLLER_HPP_

#include "main.h"
#include "hardware/motor.hpp"
#include "odometory.hpp"
#include "pid_controller.hpp"

class Controller
{
public:
    Controller(float control_period, float sampling_period);

    void Update();
    void PartyTrick();
    void MotorTest();

private:
    hardware::Motor motor;
    Odometory odom;
    PID pid_angle;
    PID pid_rotational_velocity;
    PID pid linear_velocity;

    float control_period;
    float v_left;
    float v_right;
    float u_w;
    float u_v;
};
#endif //  CONTROLLER_HPP_