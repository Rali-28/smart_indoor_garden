#ifndef soilMoistureSensor_H
#define soilMoistureSensor_H

#include <Arduino.h>

void setup_SoilMoistureSensor();
int soilMoistureDetection();
void waterPumpFunction();
void pumpOn();
void pumpOff();

#endif
