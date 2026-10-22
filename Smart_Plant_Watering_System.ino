const int moisturePin = 34;
const int relayPin = 26;

// Many relay modules are active LOW.
// Change these values if your relay behaves differently.
const int RELAY_ON = LOW;
const int RELAY_OFF = HIGH;

// Calibrate these values for your sensor.
// Example only, not universal sensor readings.
const int dryValue = 3000;
const int wetValue = 1400;

const int dryThresholdPercent = 35;
const unsigned long maxPumpTime = 5000;

bool pumpRunning = false;
unsigned long pumpStartedAt = 0;

void stopPump() {
  digitalWrite(relayPin, RELAY_OFF);
  pumpRunning = false;
}

void setup() {
  Serial.begin(115200);

  // Set the safe output state before normal operation.
  digitalWrite(relayPin, RELAY_OFF);
  pinMode(relayPin, OUTPUT);
  stopPump();
}

void loop() {
  int raw = analogRead(moisturePin);

  int moisturePercent = map(
    raw, dryValue, wetValue, 0, 100
  );
  moisturePercent = constrain(moisturePercent, 0, 100);

  Serial.print("Raw: ");
  Serial.print(raw);
  Serial.print(" | Moisture: ");
  Serial.print(moisturePercent);
  Serial.println("%");

  if (!pumpRunning &&
      moisturePercent < dryThresholdPercent) {
    digitalWrite(relayPin, RELAY_ON);
    pumpRunning = true;
    pumpStartedAt = millis();
  }

  if (pumpRunning &&
      (moisturePercent >= dryThresholdPercent + 5 ||
       millis() - pumpStartedAt >= maxPumpTime)) {
    stopPump();
  }

  delay(1000);
}
