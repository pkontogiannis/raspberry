//
// Created by Petros Kontogiannis on 7/15/18.
//

// Connect - to pin 7
// Connect s to 5V
void setup ()
{
    pinMode (7, OUTPUT); // define the digital output interface 13 feet
}
void loop () {
    digitalWrite (7, HIGH); // open the laser head
    delay (1000); // delay one second
    digitalWrite (7, LOW); // turn off the laser head
    delay (1000); // delay one second
}