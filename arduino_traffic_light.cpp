const int redPin = 7;
const int yellowPin = 6;
const int greenPin = 5;

void setup() {
    pinMode(redPin, OUTPUT);
    pinMode(yellowPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
}

void loop() {
    // Green light on
    digitalWrite(greenPin, HIGH);
    delay(20000); // 20 seconds

    // Yellow light on
    digitalWrite(greenPin, LOW);
    digitalWrite(yellowPin, HIGH);
    delay(2000); // 2 seconds

    // Red light on
    digitalWrite(yellowPin, LOW);
    digitalWrite(redPin, HIGH);
    delay(20000); // 20 seconds

    // Back to green
    digitalWrite(redPin, LOW);
}
