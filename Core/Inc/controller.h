#ifndef CONTROLLER_HPP_
#define CONTROLLER_HPP_

#include "main.h"
#include "hardware/motor.h"
#include "odometory.h"
#include "pid_controller.h"

class Controller
{
public:
    Controller(float control_period, float sampling_period);

    void OdometoryUpdate();
    void PartyTrick();
    void MotorTest();

private:
    hardware::Motor motor;
    Odometory odom;
    PID pid_angle;
    PID pid_rotational_vel;
    PID pid_linear_vel;

    float v_left;
    float v_right;
    float u_w;
    float u_v;
};
#endif //  CONTROLLER_HPP_