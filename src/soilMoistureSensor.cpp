#include <soilMoistureSensor.h>

#define moistureSensor 27
#define waterPump 4

int sensorValue;

void setup_SoilMoistureSensor()
{
    pinMode(moistureSensor, INPUT);
    pinMode(waterPump, OUTPUT);

    Serial.begin(115200);
}

void SoilMoistureDetection()
{
    int sensorValue = analogRead(moistureSensor);
    Serial.print("Soil moisture sensor value: ");
    Serial.println(sensorValue);
    /*
    Threshold
    digitalWrite(waterPump, "input value of dryness threshold" );
    digitalWrite(waterPump, "input value of wetness threshold");
    */
    delay(1000);
}