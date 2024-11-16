#include <Arduino.h>
#include <waterSensor.h>

#define trigPin 25
#define echoPin 26
int distance;

void setup_WaterSensor()
{
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);

    // Debug console
    Serial.begin(115200);
}

// TODO: Add a functionality for calculating water tank water level, will be used in Blynk app


void WaterSensorDetection()
{
    // Clear the trigPin by setting it LOW:
    digitalWrite(trigPin, LOW);

    delayMicroseconds(5);

    // Trigger the sensor by setting the trigPin high for 10 microseconds:
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Read the echoPin. pulseIn() returns the duration (length of the pulse) in microseconds:
    int duration = pulseIn(echoPin, HIGH);

    // Calculate the distance:
    //  distance = duration*0.034/2;

    distance = (duration / 2) / 29.1;
    // Print the distance on the Serial Monitor (Ctrl+Shift+M):
    // int waterLevelPer = map(distance, 22, 51, 100, 0);

    Serial.print("Distance = ");
    Serial.print(distance);
    Serial.println(" cm");
    // Serial.println(waterLevelPer);

    delay(1000);
}