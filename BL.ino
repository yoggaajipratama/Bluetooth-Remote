#include <SoftwareSerial.h>
String value;
int TxD = 11;
int RxD = 10;
int servoposition;
SoftwareSerial bluetooth(TxD, RxD);

void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  bluetooth.begin(9600);
}

void loop() {
  Serial.println(value);
  if (bluetooth.available())
  {
    value = bluetooth.readString();
    if (value == "nyalakan lampu" || value == "Nyalakan lampu"){
      digitalWrite(13, HIGH);
    }
    if (value == "matikan lampu" || value == "Matikan lampu"){
      digitalWrite(13, LOW);       
    }
  }
}
