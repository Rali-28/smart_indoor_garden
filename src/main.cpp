#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <main.h>
#include <soilMoistureSensor.h>
#include <waterSensor.h>

char ssid[] = "HUAWEI-2.4G-3k7m";
char pass[] = "4janf7lb";

#define relayPin 19

void setup()
{
    Serial.begin(115200);
    Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
    setup_SoilMoistureSensor();
    setup_WaterSensor();
    pinMode(relayPin, OUTPUT);
    Serial.begin(115200);
}

void loop()
{
    Blynk.run();
    WaterSensorDetection();
    Blynk.virtualWrite(V0, soilMoistureDetection());
    delay(1000);
}

BLYNK_WRITE(V4)
{
    // Called when the datastream V1 value changes

    // param[0] is the user time value selected in seconds.
    Serial.print("Start time in sec: ");
    Serial.println(param[0].asInt());

    // param[1] is the stop time in seconds (when option enabled)
    Serial.print("Stop time in sec: ");
    Serial.println(param[1].asInt());

    // param[2] is the timezone (Ex. "America/New_York")
    Serial.print("Timezone: ");
    Serial.println(param[2].asStr());

    // param[3] is the day of the week where 0=Sun .. 6=Sat
    Serial.print("Day of week: : ");
    Serial.println(param[3].asInt());

    // param[4] is the time zone offset from UTC in seconds
    Serial.print("param[4].asStr(): ");
    Serial.println(param[4].asInt());
}
