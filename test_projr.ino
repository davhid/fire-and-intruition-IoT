
#define BLYNK_TEMPLATE_ID "Your_Template_ID"
#define BLYNK_TEMPLATE_NAME "Your_Template_Name"
#define BLYNK_AUTH_TOKEN "Your_Auth_Token"

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Blynk Auth Token
char auth[] = "Your_Blynk_Auth_Token";

// WiFi credentials
char ssid[] = "Your_WiFi_SSID";
char pass[] = "Your_WiFi_Password";

// Pin assignments
const int flameSensorPin = D6;  // Flame sensor connected to GPIO12 (D6)
const int smokeSensorPin = A0; // Smoke sensor connected to A0 (Analog pin)
const int ledPin = D7;         // LED connected to GPIO13 (D7)
const int buzzerPin = D2;      // Buzzer connected to GPIO4 (D2)
const int relayPin = D1;       // Relay connected to GPIO5 (D1)

// Threshold for smoke sensor
const int smokeThreshold = 400;

BlynkTimer timer;

// Function to check sensors and trigger alarms
void checkSensors() {
  // Read flame sensor
  int flameStatus = digitalRead(flameSensorPin);

  // Read smoke sensor
  int smokeLevel = analogRead(smokeSensorPin);

  // Send data to Blynk app
  Blynk.virtualWrite(V0, flameStatus); // Flame sensor status
  Blynk.virtualWrite(V1, smokeLevel); // Smoke sensor level

  Serial.print("Flame Status: ");
  Serial.println(flameStatus);
  Serial.print("Smoke Level: ");
  Serial.println(smokeLevel);

  if (flameStatus == LOW || smokeLevel > smokeThreshold) {
    // Trigger alarms
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(relayPin, HIGH);

    // Notify and send email
    if (flameStatus == LOW) {
      Blynk.notify("Fire Alert: Flame detected!");
      Blynk.email("your_email@example.com", "Fire Alert", "A flame has been detected!");
    }

    if (smokeLevel > smokeThreshold) {
      Blynk.notify("Smoke Alert: High smoke levels detected!");
      Blynk.email("your_email@example.com", "Smoke Alert", "High smoke levels detected!");
    }
  } else {
    // Turn off alarms
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);
    digitalWrite(relayPin, LOW);
  }
}

void setup() {
  // Debug console
  Serial.begin(9600);

  // Set pin modes
  pinMode(flameSensorPin, INPUT);
  pinMode(smokeSensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(relayPin, OUTPUT);

  // Initialize Blynk
  Blynk.begin(auth, ssid, pass);

  // Set up a timer to check sensors every second
  timer.setInterval(1000L, checkSensors);
}

void loop() {
  Blynk.run();
  timer.run();
}
