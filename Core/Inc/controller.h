#ifndef CONTROLLER_HPP_
#define CONTROLLER_HPP_

#include "main.h"
#include "hardware/motor.h"
#include "pid_controller.h"

namespace undercarriage
{
    class Controller
    {
    public:
        Controller(float control_period);

        void PartyTrick(float theta, float omega);
        void MotorTest();

    private:
        hardware::Motor motor;
        PID pid_angle;
        PID pid_rotational_vel;
        PID pid_linear_vel;

        float v_left;
        float v_right;
        float u_w;
        float u_v;
    };
} // namespace undercarriage

#endif //  CONTROLLER_HPP_