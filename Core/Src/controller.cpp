#include "controller.h"

Controller::Controller(float control_period, float sampling_period)
    : motor(1000),
      odom(sampling_period, 0.0125, 16.4),
      pid_angle(2.0, 2.0, 0.05, 0.0, control_period),
      pid_rotational_vel(1.59, 60.0, -0.00213, 0.0, control_period),
      pid_linear_vel(19.72, 52.0, 1.548, 0.0, control_period) {}

void Controller::OdometoryUpdate()
{
    odom.Update();
}

void Controller::PartyTrick()
{
    u_w = pid_angle.Update(-odom.theta);
    v_left = -u_w;
    v_right = u_w;
    motor.Drive(v_left, v_right);
}

void Controller::MotorTest()
{
    motor.Drive(1.5, 1.5); // voltage [V]
}