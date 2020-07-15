#include "pitches.h"
const int ledPin = 13;
const int buzzerPin = 12;
const int ldrPin = A0;

void setup() {
  Serial.begin(9600);

  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ldrPin, INPUT);

}

void loop() {
  
  int ldrStatus = analogRead(ldrPin);

  if (ldrStatus >= 300) {

    int melody[] = {NOTE_D3, NOTE_D3, NOTE_D4, NOTE_A3, NOTE_GS3, NOTE_G3, NOTE_F3, NOTE_D3, NOTE_F3, NOTE_G3};
    int noteDurations[] = {6, 6, 5, 4, 5, 5, 5, 8, 8, 8};

    for (int thisNote = 0; thisNote < 10; thisNote++) {
      int noteDuration = 1000 / noteDurations[thisNote];
      tone(buzzerPin, melody[thisNote], noteDuration);
      digitalWrite(ledPin, HIGH);

      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);

      noTone(buzzerPin);
    }
    /*tone(buzzerPin, 100);
    digitalWrite(ledPin, HIGH);
    delay(100);

    noTone(buzzerPin);
    digitalWrite(ledPin, LOW);
    delay(100);*/
  } else {

    noTone(buzzerPin);
    digitalWrite(ledPin, LOW);
  }
}
