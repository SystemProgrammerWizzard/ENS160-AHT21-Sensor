#include "ens160.hpp"

ENS160::ENS160()
    : ens160(ENS160_I2CADDR_1),
      aqi(0), tvoc(0), echo2(0),
      r_hp0(0), r_hp1(0), r_hp2(0), r_hp3(0),
      is_initialized(false) {}


void ENS160::init(){
    if (!ens160.available()){
        Serial.println("ENS160 initialized successfully");
        Serial.println(ens160.setMode(ENS160_OPMODE_STD) ? "done." : "failed!");

    }
    else {
        Serial.println("Failed to initialized ENS160");
    }
}



void ENS160::get_value(float temp, float humidity){
    if (is_initialized) {
        Serial.println("ENS160 already initialized");
        return;
    }
    ens160.set_envdata(temp, humidity);
    ens160.measure(true);
    ens160.measureRaw(true);
        aqi = ens160.getAQI();
        tvoc = ens160.getTVOC();
        echo2 = ens160.geteCO2();
        r_hp0 = ens160.getHP0();
        r_hp1 = ens160.getHP1();
        r_hp2 = ens160.getHP2();
        r_hp3 = ens160.getHP3();

}

float ENS160::get_aqi() {
    if (is_initialized) {
        Serial.println("ENS160 not initialized");
        
    }
    return aqi;
}

float ENS160::get_tvco() {
    if (is_initialized) {
        Serial.println("ENS160 not initialized");
        
    }
    return tvoc;
}

float ENS160::get_echo2() {
    if (is_initialized) {
        Serial.println("ENS160 not initialized");
        
    }
    return echo2;
}

float ENS160::get_r_hp0() {
    if (is_initialized) {
        Serial.println("ENS160 not initialized");
        
    }
    return r_hp0;
}

float ENS160::get_r_hp1() {
    if (is_initialized) {
        Serial.println("ENS160 not initialized");
        
    }
    return r_hp1;
}

float ENS160::get_r_hp2() {
    if (is_initialized) {
        Serial.println("ENS160 not initialized");
        
    }
    return r_hp2;
}

float ENS160::get_r_hp3() {
    if (is_initialized) {
        Serial.println("ENS160 not initialized");
        
    }
    return r_hp3;
}
void ENS160::display() {
    if (is_initialized) {
        Serial.println("ENS160 not initialized");
        return;
    }

    Serial.println("🔎 ENS160 Sensor Readings:");
    Serial.print("  • AQI: "); Serial.println(aqi);
    Serial.print("  • TVOC: "); Serial.print(tvoc); Serial.println(" ppb");
    Serial.print("  • eCO2: "); Serial.print(echo2); Serial.println(" ppm");
    Serial.print("  • R_HP0: "); Serial.println(r_hp0);
    Serial.print("  • R_HP1: "); Serial.println(r_hp1);
    Serial.print("  • R_HP2: "); Serial.println(r_hp2);
    Serial.print("  • R_HP3: "); Serial.println(r_hp3);
    Serial.println("------------------------------------");
}