#ifndef HARDWARE_IR_SENSOR_HPP_
#define HARDWARE_IR_SENSOR_HPP_

#include "main.h"
#include "hardware/led.h"

namespace hardware
{
    class IRsensor
    {
    private:
        LED led;
        const int sampling_count = 16;
        uint32_t threshold; // 2100

        uint16_t dma_f[3];
        uint16_t dma_b[2];

        uint32_t fl[16];
        uint32_t fr[16];
        uint32_t sl[16];
        uint32_t sr[16];

        uint32_t ir_fl;
        uint32_t ir_fr;
        uint32_t ir_sl;
        uint32_t ir_sr;

        float bat_vol;

    public:
        IRsensor(uint32_t threshold);
        // IRsensor(int sampling_count);

        void on_front_led();
        void on_side_led();
        void off_front_led();
        void off_side_led();
        void on_all_led();
        void off_all_led();

        void UI_led_onoff();
        void UI_led_off();

        void UpdateSideValue();
        void UpdateFrontValue();
        void Update();
        float GetBatteryVoltage();
        void BatteryCheck();
        bool StartInitialize();
    };
}
#endif //  HARDWARE_IR_SENSOR_HPP_