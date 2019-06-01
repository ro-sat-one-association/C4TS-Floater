#include <SoftwareSerial.h>

SoftwareSerial s = SoftwareSerial(8,7);

void setup() {
        Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
        s.begin(9600);
        pinMode(13, OUTPUT);
}

void loop() {
        digitalWrite(13, HIGH);
        // send data only when you receive data:
        if (Serial.available() > 0) {
                // read the incoming byte:
                char i = Serial.read();
                s.print(i);
        }
        if (s.available() > 0) {
                // read the incoming byte:
                char i = s.read();
                Serial.print(i);
        }
}
