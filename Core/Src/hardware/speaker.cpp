#include "hardware/speaker.hpp"

namespace hardware
{
    Speaker::Alert()
    {
        __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, 10);
        HAL_Delay(30);
        __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, 0);
    }
} // namespace hardware