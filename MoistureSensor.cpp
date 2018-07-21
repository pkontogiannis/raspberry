//
// Created by Petros Kontogiannis on 7/15/18.
//

const int sensor_pin = A0; // Analog pin 0
const int max_value = 1020; // moisture = 0
const int min_value = 200; // moisture = 100
const int low_value = 30, medium_value = 70,high_value = 90;

void setup() {
    Serial.begin(9600);
}

void LedState(int state) {
    digitalWrite(13, state);
}

void loop() {
    int moisture_level = analogRead(sensor_pin);
    int moisture = map(moisture_level, max_value, min_value, 0, 100);
    if (moisture < low_value) {
        Serial.print("Low (");
        Serial.print(moisture);
        Serial.println(")%");
    } else if (moisture < medium_value){
        Serial.print("Medium (");
        Serial.print(moisture);
        Serial.println(")%");
    } else {
        Serial.print("High (");
        Serial.print(moisture);
        Serial.println(")%");
    }
    delay(500);
}
