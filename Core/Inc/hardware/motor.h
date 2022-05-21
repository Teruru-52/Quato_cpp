#ifndef HARDWARE_MOTOR_HPP_
#define HARDWARE_MOTOR_HPP_

#include "main.h"
#include "hardware/ir_sensor.h"

namespace hardware
{
    class Motor
    {
    private:
        // IRsensor battery;

        int max_input;
        float duty_left;
        float duty_right;

    public:
        Motor(int max_input);

        int GetDuty(float input_vol);
        void Drive(float v_left, float v_right);
        void Brake();
        void Free();
    };
} // namespace hardware
#endif //  HARDWARE_MOTOR_HPP_