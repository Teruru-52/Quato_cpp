#ifndef HARDWARE_MOTOR_HPP_
#define HARDWARE_MOTOR_HPP_

#include "main.h"

namespace hardware
{
    class Motor
    {
    public:
        Motor(int max_input);

        int GetDuty(float input_vol);
        void Drive(float v_left, float v_right);
        void Brake();
        void Free();

    private:
        int max_input;
        float duty_left;
        float duty_right;
        float bat_vol;
    };
} // namespace hardware
#endif //  HARDWARE_MOTOR_HPP_