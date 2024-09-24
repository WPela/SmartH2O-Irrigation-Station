#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// OLED display settings
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1); // OLED I2C, no reset pin

// LED pin and WiFi credentials
#define LED_PIN D0  // GPIO16 (D0)
const char* ssid = "NETIASPOT-2,4GHz-6EF82C";
const char* password = "NchoL3F3JGKa";

void setup() {
  // Initialize serial communication
  Serial.begin(115200);
  Serial.println("Booting");

  // Connect to WiFi
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.println("Connection Failed! Rebooting...");
    delay(5000);
    ESP.restart();
  }

  // Setup OTA updates
  ArduinoOTA.onStart([]() { Serial.println("Start"); });
  ArduinoOTA.onEnd([]() { Serial.println("\nEnd"); });
  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
  });
  ArduinoOTA.onError([](ota_error_t error) {
    Serial.printf("Error[%u]: ", error);
    if (error == OTA_AUTH_ERROR) Serial.println("Auth Failed");
    else if (error == OTA_BEGIN_ERROR) Serial.println("Begin Failed");
    else if (error == OTA_CONNECT_ERROR) Serial.println("Connect Failed");
    else if (error == OTA_RECEIVE_ERROR) Serial.println("Receive Failed");
    else if (error == OTA_END_ERROR) Serial.println("End Failed");
  });
  ArduinoOTA.begin();

  // Display IP address on Serial monitor
  Serial.println("Ready");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  // Initialize LED pin
  pinMode(LED_PIN, OUTPUT);

  // Initialize OLED display
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    while (true); // Stop if display initialization fails
  }

  // Clear display buffer
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(5);
  display.setCursor(0, 0);
}

void loop() {
  ArduinoOTA.handle();

  // Turn LED ON (active low on ESP8266)
  digitalWrite(LED_PIN, HIGH);
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("ON");
  display.display();
  delay(2000);

  // Turn LED OFF
  digitalWrite(LED_PIN, LOW);
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("OFF");
  display.display();
  delay(2000);
}
