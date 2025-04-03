#ifndef ENS160_H
#define ENS160_H

#include "ScioSense_ENS160.h"

class ENS160 {
    private: 
        float aqi, tvoc, echo2, r_hp0, r_hp1, r_hp2, r_hp3;
        ScioSense_ENS160 ens160;
        bool is_initialized;
    public:
        ENS160();
        void init();
        void get_value(float, float);
        float get_aqi();
        float get_tvco();
        float get_echo2();
        float get_r_hp0();
        float get_r_hp1();
        float get_r_hp2();
        float get_r_hp3();
        void display();
    };

#endif // ENS160_H