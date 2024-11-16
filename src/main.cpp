#include <Arduino.h>
#include <waterSensor.h>

void setup()
{
  setup_WaterSensor();
}

void loop()
{
  WaterSensorDetection();
}
