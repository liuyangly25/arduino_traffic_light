const int redPin = 7;
const int yellowPin = 6;
const int greenPin = 5;

const int trigPin = 9; // Ultrasonic sensor trigger
const int echoPin = 10; // Ultrasonic sensor echo

long duration;
int distance;
const int distanceThreshold = 10; // 10 cm threshold for detecting traffic

void setup() {
    pinMode(redPin, OUTPUT);
    pinMode(yellowPin, OUTPUT);
    pinMode(greenPin, OUTPUT);

    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);

    Serial.begin(9600);
}

void loop() {
    int greenTime = checkTraffic() ? 8000 : 5000; // Extend green if traffic is detected

    // Green light phase
    digitalWrite(greenPin, HIGH);
    delay(greenTime);

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

// Function to check for traffic using the ultrasonic sensor
bool checkTraffic() {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);
    distance = duration * 0.034 / 2; // Convert to cm

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    return (distance > 0 && distance < distanceThreshold);
}
