#include "controller.h"

namespace undercarriage
{
    Controller::Controller(float control_period)
        : motor(1000),
          pid_angle(2.0, 2.0, 0.05, 0.0, control_period),
          pid_rotational_vel(1.59, 60.0, -0.00213, 0.0, control_period),
          pid_linear_vel(19.72, 52.0, 1.548, 0.0, control_period) {}

    void Controller::PartyTrick(float theta, float omega)
    {
        u_w = pid_angle.Update(-theta) + pid_rotational_vel.Update(-omega);
        v_left = -u_w;
        v_right = u_w;
        motor.Drive(v_left, v_right);
    }

    void Controller::MotorTest()
    {
        motor.Drive(1.5, 1.5); // voltage [V]
    }
}