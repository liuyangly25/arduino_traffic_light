const int redPin = 7;
const int yellowPin = 6;
const int greenPin = 5;

const int ldrPin = A0;  // LDR sensor pin
const int lightThreshold = 300;  // Night mode threshold

void setup() {
    pinMode(redPin, OUTPUT);
    pinMode(yellowPin, OUTPUT);
    pinMode(greenPin, OUTPUT);

    Serial.begin(9600);
}

void loop() {
    int lightLevel = analogRead(ldrPin);

    if (lightLevel < lightThreshold) {
        nightMode();  // If it's dark, enable blinking yellow mode
    } else {
        normalTrafficMode();  // Normal traffic light cycle
    }
}

void normalTrafficMode() {
    // Green light phase
    digitalWrite(greenPin, HIGH);
    delay(5000);

    // Yellow light phase
    digitalWrite(greenPin, LOW);
    digitalWrite(yellowPin, HIGH);
    delay(2000);

    // Red light phase
    digitalWrite(yellowPin, LOW);
    digitalWrite(redPin, HIGH);
    delay(5000);

    digitalWrite(redPin, LOW);
}

void nightMode() {
    while (analogRead(ldrPin) < lightThreshold) { // Stay in night mode until daylight
        digitalWrite(yellowPin, HIGH);
        delay(500);
        digitalWrite(yellowPin, LOW);
        delay(500);
    }
}
