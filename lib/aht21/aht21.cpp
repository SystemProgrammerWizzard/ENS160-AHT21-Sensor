#include "aht21.hpp"


AHT21::AHT21() : temp(0), humidity(0), is_initialized(false) {}

void AHT21::init()
{
    if (!aht.begin()) {
        Serial.println("Failed to initialize AHT21");
    }
    else
    {
        Serial.println("AHT21 initialized successfully");
    }
}

void AHT21::get_value()
{
    if (is_initialized) {
        Serial.println("AHT21 not initialized");
        return;
    }
    sensors_event_t temp_event, humidity_event;
    aht.getEvent(&humidity_event, &temp_event); // Get both
    temp = temp_event.temperature;
    humidity = humidity_event.relative_humidity;
}

float AHT21::get_temperature()
{
    if (is_initialized) {
        Serial.println("AHT21 not initialized");
        return 0;
    }
    return temp;
}

float AHT21::get_humidity()
{
    if (is_initialized) {
        Serial.println("AHT21 not initialized");
        return 0;
    }
    return humidity;
}

void AHT21::display()
{
    if (is_initialized) {
        Serial.println("AHT21 not initialized");
        return;
    }


    Serial.print("Temp: ");
    Serial.print(temp);
    Serial.print(" °C, Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");
}

