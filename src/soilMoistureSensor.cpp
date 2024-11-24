#include <soilMoistureSensor.h>

#define moistureSensor 34
// *ACTIVE-LOW RELAY
#define waterPump 4

// Variable data storage
// Holds sensor value and its corresponding percentage
int sensorValue;
int moisturePercentage;

// Constant values for sensor
int drySoil = 4095;
int wetSoil = 3500;
int moisturePerLow = 20;  // low moisture percentage
int moisturePerHigh = 80; // High moisture percentage

// Boolean for getting the waterpump state
bool waterPumpState = true; // Pump is off (active-LOW relay)

void setup_SoilMoistureSensor()
{
    pinMode(moistureSensor, INPUT);
    pinMode(waterPump, OUTPUT);
    digitalWrite(waterPump, HIGH);
    Serial.begin(115200);
}

int soilMoistureDetection()
{
    // Gets the analog input sensor value of the soil moisture sensor
    int sensorValue = analogRead(moistureSensor);
    Serial.print("Soil moisture sensor value: ");
    Serial.println(sensorValue);

    // Converts the analog input into percentage
    moisturePercentage = map(sensorValue, drySoil, wetSoil, 0, 100);
    moisturePercentage = constrain(moisturePercentage, 0, 100);
    Serial.print("Soil moisture percentage: ");
    Serial.print(moisturePercentage);
    Serial.println("%");
    return moisturePercentage;
}

void waterPumpFunction()
{
    // Turns on water pump if moisture gets too low
    if (moisturePercentage < moisturePerLow && waterPumpState == true)
    {
        pumpOn();
    }
    // Turns off water pump at the right moisture level
    else if (moisturePercentage > moisturePerHigh && waterPumpState == false)
    {
        pumpOff();
    }
}

void pumpOn()
{
    digitalWrite(waterPump, LOW); // *Turn pump on (active-LOW relay)
    Serial.println("PUMP ON");
    waterPumpState = false; // update state to pump on
}

void pumpOff()
{
    digitalWrite(waterPump, HIGH); // *Turn pump off (active-LOW relay)
    Serial.println("PUMP OFF");
    waterPumpState = true; // update state to pump off
}