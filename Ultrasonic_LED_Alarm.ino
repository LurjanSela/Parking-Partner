#include <Adafruit_NeoPixel.h>

#define trigPin1 6 // US Set #1
#define echoPin1 5
#define trigPin2 4//US Set #2
#define echoPin2 3
#define LED_PIN1 10 // Pin for the WS2812B LED strip #1
// #define LED_PIN2 9 // Pin for the WS2812B LED strip #2
// #define pin 22

#define NUM_LEDS 10 // Number of LEDs in the strip
#define buzzerPin 2 //Pin for the buzzer

Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(NUM_LEDS, LED_PIN1, NEO_GRB + NEO_KHZ800);
// Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(NUM_LEDS, LED_PIN2, NEO_GRB + NEO_KHZ800);

volatile unsigned long duration1, duration2, distance1, distance2;

void setup() {
  Serial.begin(2000000);
  pinMode(trigPin1, OUTPUT); pinMode(trigPin2, OUTPUT);
  pinMode(echoPin1, INPUT); pinMode(echoPin2, INPUT);
  strip1.begin(); // Initialize the LED strip 1
 // strip2.begin(); // Initialize the LED strip 2
}

void loop() {

  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  
  distance1 = (duration1 / 58) ; distance2 = (duration2 / 58);

  // Set the color of the LED strip based on distance
  if (distance1 > 137) {
    colorWipe(strip1, strip1.Color(0, 255, 0), 50, 0); // Green
  } else if (distance1 > 75) {
    colorWipe(strip1, strip1.Color(255, 255, 0), 50, 0); // Yellow
  } else {
    colorWipe(strip1, strip1.Color(255, 0, 0), 50, 0); // Red
  }

    // Set the color of the LED strip based on distance
  if (distance2 > 137) {
    colorWipe(strip1, strip1.Color(0, 255, 0), 50, 5); // Green
  } else if (distance1 > 75) {
    colorWipe(strip1, strip1.Color(255, 255, 0), 50, 5); // Yellow
  } else {
    colorWipe(strip1, strip1.Color(255, 0, 0), 50, 5); // Red
  }

  // Sound the buzzer if the smallest distance is less than or equal to 13 cm
  if ( (distance1||distance2) <= 13) {
    tone(2, 1000 / (min(distance1,distance2) + 1)); // Set the buzzer frequency based on distance
    delay(500); // Wait for 500 milliseconds
    noTone(2); // Stop the buzzer sound
    delay(500); // Wait for 500 milliseconds
  }

  // Print the distance to the serial monitor
  Serial.print(distance1);
  Serial.println(" and ");
  Serial.print(distance2);
  Serial.println(" cm");
}

void colorWipe(Adafruit_NeoPixel &strip, uint32_t color, int wait, int ultraSonicAddr) {
  for (int i = 0; i < (strip.numPixels())/2; i++) {
    strip.setPixelColor( (i + ultraSonicAddr), color);
    strip.show();
    delay(wait);
  }
  Serial.println("Diagnosing color values for strip");
  Serial.print(ultraSonicAddr);
  Serial.println("Color Value =");
  Serial.print(color);
  Serial.println(" ");
}
