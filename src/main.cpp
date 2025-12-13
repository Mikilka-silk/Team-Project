#include "main.h"

void handleRoot() {
  server.send(200, "text/html", html);
}

void handleOn() {
  digitalWrite(LED_PIN, HIGH);
  server.send(200, "text/plain", "LED ON");
}

void handleOff() {
  digitalWrite(LED_PIN, LOW);
  server.send(200, "text/plain", "LED OFF");
}

void setup() {
  pinMode(LED_PIN, OUTPUT);

  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() !=WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  Serial.println("IP Adress: ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.on("/open", handleOn);
  server.on("/close", handleOff);

  server.begin();
}

void loop() {
  server.handleClient();
}