const int redPin = 7;
const int yellowPin = 6;
const int greenPin = 5;
const int buttonPin = 2;

bool pedestrianRequest = false;

void setup() {
    pinMode(redPin, OUTPUT);
    pinMode(yellowPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(buttonPin, INPUT_PULLUP); // Internal pull-up resistor

    attachInterrupt(digitalPinToInterrupt(buttonPin), requestCrossing, FALLING);
}

void loop() {
    if (pedestrianRequest) {
        handlePedestrianCrossing();
        pedestrianRequest = false; // Reset request
    } else {
        normalTrafficCycle();
    }
}

void normalTrafficCycle() {
    digitalWrite(greenPin, HIGH);
    delay(5000);

    digitalWrite(greenPin, LOW);
    digitalWrite(yellowPin, HIGH);
    delay(2000);

    digitalWrite(yellowPin, LOW);
    digitalWrite(redPin, HIGH);
    delay(5000);

    digitalWrite(redPin, LOW);
}

void handlePedestrianCrossing() {
    // Immediately stop cars safely
    digitalWrite(greenPin, LOW);
    digitalWrite(yellowPin, HIGH);
    delay(2000);

    digitalWrite(yellowPin, LOW);
    digitalWrite(redPin, HIGH);
    delay(5000); // Give pedestrians time to cross

    digitalWrite(redPin, LOW);
}

void requestCrossing() {
    pedestrianRequest = true;
}
