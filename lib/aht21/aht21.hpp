#ifndef AHT21_H
#define AHT21_H

#include <Adafruit_AHTX0.h>

class AHT21 {
    private:
        float temp, humidity;
        Adafruit_AHTX0 aht;
        bool is_initialized;
    public: 
        AHT21();
        void init();
        void get_value();
        float get_temperature();
        float get_humidity();
        void display();


};

#endif // AHT21_H