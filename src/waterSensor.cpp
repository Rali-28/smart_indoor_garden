#include <waterSensor.h>
#include <soilMoistureSensor.h>

#define s1_trigPin 25
#define s1_echoPin 26
#define s2_trigPin 16
#define s2_echoPin 17
int distance_1;
int distance_2;

void setup_WaterSensor()
{
    pinMode(s1_trigPin, OUTPUT);
    pinMode(s1_echoPin, INPUT);
    pinMode(s2_trigPin, OUTPUT);
    pinMode(s2_echoPin, INPUT);

    // Debug console
    Serial.begin(115200);
}

// TODO: Add a functionality for calculating water tank water level, will be used in Blynk app
// TODO: Will Use Two Water Sensor for Full and Empty

void WaterSensorDetection()
{
    firstSensor();
    secondSensor();

    Serial.print("Distance_1 = ");
    Serial.print(distance_1);
    Serial.println(" cm");

    Serial.print("Distance_2 = ");
    Serial.print(distance_2);
    Serial.println(" cm");

    if (distance_1 == 20 && distance_2 == 20)
    {
        Serial.println("Water Tank: Full");
        waterPumpFunction();
    }
    else if(distance_1 == 20){
        waterPumpFunction();
    }
    else if (distance_1 > 20 && distance_2 > 20)
    {
        Serial.println("Water Tank: EMPTY");
        pumpOff();
    }
}

void firstSensor()
{
    // Clear the trigPin by setting it LOW:
    digitalWrite(s1_trigPin, LOW);
    delayMicroseconds(5);

    // Trigger the sensor by setting the s1_trigPin high for 10 microseconds:
    digitalWrite(s1_trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(s1_trigPin, LOW);

    // Read the echoPin. pulseIn() returns the duration (length of the pulse) in microseconds:
    int duration_1 = pulseIn(s1_echoPin, HIGH);

    // Calculate the distance:
    distance_1 = (duration_1 / 2) / 29.1;
}

void secondSensor()
{
    digitalWrite(s2_trigPin, LOW);
    delayMicroseconds(5);

    digitalWrite(s2_trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(s2_trigPin, LOW);

    int duration_2 = pulseIn(s2_echoPin, HIGH);

    distance_2 = (duration_2 / 2) / 29.1;
}