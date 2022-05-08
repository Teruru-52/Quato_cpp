#include "hardware/encoder.hpp"

#include <cmath>

namespace hardware
{
    Encoder::Encoder(float sampling_period, float tire_radius)
        : sampling_period(sampling_period),
          tire_radius(tire_radius) {}

    void Encoder::Update()
    {
        Update_L();
        Update_R();
    }

    void Encoder::Update_L()
    {
        pulse_left = 0;
        uint16_t enc_buff = TIM3->CNT;
        TIM3->CNT = 0;

        if (enc_buff > 32767)
        {
            pulse_left = (int16_t)enc_buff * -1;
        }
        else
        {
            pulse_left = (int16_t)enc_buff;
        }
    }

    void Encoder::Update_R()
    {
        pulse_right = 0;
        uint16_t enc_buff = TIM4->CNT;
        TIM4->CNT = 0;

        if (enc_buff > 32767)
        {
            pulse_right = (int16_t)enc_buff * -1;
        }
        else
        {
            pulse_right = (int16_t)enc_buff;
        }
    }

    float Encoder::GetAngularVelocity(int16_t pulse)
    {
        return pulse * (2.0 * pi / ppr) * gear_ratio / sampling_period;
    }

    float Encoder::GetVelocity()
    {
        return (GetAngularVelocity(pulse_left) + GetAngularVelocity(pulse_right)) / 2.0;
    }
} // namespace hardware