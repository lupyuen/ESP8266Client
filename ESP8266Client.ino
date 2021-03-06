//  This is the client code for ESP8266 Arduino Shield by http://www.doit.am/
//  Sends the light sensor and temperature sensor values to the cloud via UDP.
//  Need to set the ESP8266 as STA mode, Socket Type=Client, Transport Type=UDP, Remote IP=(this PC), Remote Port=9000
//  Switch                                             the dual-port switch to OFF, upload the sketch, then switch to ON.

//  LED connected at pin D13
//  Temperature sensor AM2302 connected at pin D5 with 5V
//  Light sensor 595391 connected at pin A0 with 5V

#define LED_PIN 13
#define LIGHT_SENSOR_PIN A0

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // initialize LED pin as an output.
  pinMode(LED_PIN, OUTPUT);

  //  Set up the temperature sensor.
  dht22_setup();
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);              // wait for a second
  //  Send a UDP message to the server.
  Serial.println("hello this is ESP8266Client");

  //  Blink the LED.
  digitalWrite(LED_PIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);              // wait for a second
  digitalWrite(LED_PIN, LOW);    // turn the LED off by making the voltage LOW

  //  Read the light sensor.  Returns a range from 0 (very bright) to 1023 (very dark).
  int lightLevel = analogRead(LIGHT_SENSOR_PIN);
  Serial.print("LightLevel: ");
  Serial.println(lightLevel);

  //  Read from the temperature sensor.
  dht22_loop();
}

