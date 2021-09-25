#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

cost char* ssid = "REPLACE_WITH_YOUR_SSID";
cost char* password = "REPLACE_WITH_YOUR_PASSWORD"


unsigned long flowPulses = 0, lastTime = 0;
bool memFlow = false;

void setup() {
  Serial.begin(9600);
  pinMode(5,INPUT);
  Serial.println("Configuracion terminada");
}

void loop() {
  bool currentFlow = digitalRead(5);
  if(memFlow != currentFlow){
    flowPulses++;
    memFlow = currentFlow;
    delay(2);
  }
  
  unsigned long now = millis();
  if(now - lastTime > 1000){
    Serial.println(flowPulses);
    lastTime = now;
  }
}
