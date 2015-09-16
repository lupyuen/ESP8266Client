//  This is the client code for ESP8266 Arduino Shield by http://www.doit.am/
//  Set the ESP8266 as STA mode, Socket Type=Client, Transport Type=UDP, Remote IP=(this PC), Remote Port=9000
//  Switch                                             the dual-port switch to OFF, upload the sketch, then switch to ON.

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);              // wait for a second
  Serial.println("hello this is ESP8266Client");
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);              // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
}
