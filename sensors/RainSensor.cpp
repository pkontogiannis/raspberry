//
// Created by Petros Kontogiannis on 7/15/18.
//

const int sensor_pin = A3; // Analog pin 3
const int sensor_digital_pin = 2;
const int max_value = 1023; // moisture = 0
const int min_value = 200; // moisture = 100
const int low_value = 300, medium_value = 700, high_value = 900, no_rain = 1000;

int rain_value;
boolean rain_status = false;
String rain_status_msg, rain_level_msg;

void setup() {
    Serial.begin(9600);
    pinMode(2,INPUT);
}

void loop() {
    rain_value = analogRead(sensor_pin);
    rain_status = !(digitalRead(sensor_digital_pin));

    if(rain_status){
        rain_status_msg = "It's raining!";
    }
    else{
        rain_status_msg = "It's not raining.";
    }

    if (rain_value > no_rain){
        rain_level_msg = "Nothing";
    } else if (rain_value > high_value){
        rain_level_msg = "Low";
    } else if (rain_value > medium_value) {
        rain_level_msg = "Medium";
    } else {
        rain_level_msg = "High";
    }

    Serial.print("Raining?: ");
    Serial.print(rain_status_msg);
    Serial.print("\t Rain Level: ");
    Serial.print(rain_level_msg);
    Serial.print(" (");
    Serial.print(rain_value);
    Serial.print(") \n");
    delay(1000);

}