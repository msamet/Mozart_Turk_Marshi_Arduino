/*
  Melody

 Plays a melody

 circuit:
 * 8-ohm speaker on digital pin 8

 created 21 Jan 2010
 modified 30 Aug 2011
 by Tom Igoe

This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/Tone

 */
#include "pitches.h"

// notes in the melody:
int melody[] = {
  NOTE_B4, NOTE_A4, NOTE_GS4, NOTE_A4, NOTE_C5, 
  NOTE_D5, NOTE_C5, NOTE_B4, NOTE_C5, NOTE_E5,
  NOTE_F5, NOTE_E5, NOTE_DS5, NOTE_E5, 
  NOTE_B5, NOTE_A5, NOTE_GS5, NOTE_A5, NOTE_B5, NOTE_A5, NOTE_GS5, NOTE_A5, NOTE_C6,
  NOTE_A5, NOTE_C6, NOTE_G5, NOTE_A5, NOTE_B5, NOTE_A5,
  NOTE_G5, NOTE_A5, NOTE_G5, NOTE_A5, NOTE_B5, NOTE_A5, NOTE_G5, NOTE_A5, NOTE_G5, NOTE_A5, NOTE_B5, NOTE_A5, NOTE_G5, NOTE_FS5, NOTE_E5,
  NOTE_E5, NOTE_F5, NOTE_G5, NOTE_G5, NOTE_A5, NOTE_G5, NOTE_F5, NOTE_E5, NOTE_D5,
  NOTE_E5, NOTE_F5, NOTE_G5, NOTE_G5, NOTE_A5, NOTE_G5, NOTE_F5, NOTE_E5, NOTE_D5,
  NOTE_C5, NOTE_D5, NOTE_E5, NOTE_E5, NOTE_F5, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_B4,
  NOTE_C5, NOTE_D5, NOTE_E5, NOTE_E5, NOTE_F5, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_B4,
  NOTE_B4, NOTE_A4, NOTE_GS4, NOTE_A4, NOTE_C5, 
  NOTE_D5, NOTE_C5, NOTE_B4, NOTE_C5, NOTE_E5,
  NOTE_F5, NOTE_E5, NOTE_DS5, NOTE_E5, 
  NOTE_B5, NOTE_A5, NOTE_GS5, NOTE_A5, NOTE_B5, NOTE_A5, NOTE_GS5, NOTE_A5, NOTE_C6,
  NOTE_A5, NOTE_B5, NOTE_C6,  NOTE_B5, NOTE_A5, NOTE_GS5, NOTE_A5, NOTE_E5, NOTE_F5, NOTE_D5, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_A4,
  NOTE_A5, NOTE_B5, NOTE_CS6, NOTE_A5, NOTE_B5, NOTE_CS6,  NOTE_B5,NOTE_A5,NOTE_GS5,NOTE_FS5,NOTE_GS5,NOTE_A5, NOTE_B5,NOTE_GS5,NOTE_E5,
  NOTE_A5, NOTE_B5, NOTE_CS6, NOTE_A5, NOTE_B5, NOTE_CS6,  NOTE_B5,NOTE_A5,NOTE_GS5,NOTE_FS5, NOTE_B5,NOTE_GS5,NOTE_E5,NOTE_A5,
  NOTE_A5, NOTE_B5, NOTE_CS6, NOTE_A5, NOTE_B5, NOTE_CS6,  NOTE_B5,NOTE_A5,NOTE_GS5,NOTE_FS5,NOTE_GS5,NOTE_A5, NOTE_B5,NOTE_GS5,NOTE_E5,
  NOTE_A5, NOTE_B5, NOTE_CS6, NOTE_A5, NOTE_B5, NOTE_CS6,  NOTE_B5,NOTE_A5,NOTE_GS5,NOTE_FS5, NOTE_B5,NOTE_GS5,NOTE_E5,NOTE_A5,
    
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  8, 8, 8, 8, 2, 
  8, 8, 8, 8, 2, 
  8, 8, 8, 8,
  8,8,8,8,8,8,8,8,2,
  4,4,16,16,16,4,
  4,4,16,16,16,4,4,4,16,16,16,4,4,4,2,
  4,4,4,4,8,8,8,8,2,
  4,4,4,4,8,8,8,8,2,
  4,4,4,4,8,8,8,8,2,
  4,4,4,4,8,8,8,8,2,
  8, 8, 8, 8, 2, 
  8, 8, 8, 8, 2, 
  8, 8, 8, 8, 
  8,8,8,8,8,8,8,8,2,
  4,4,4,4,4,4,4,4,4,4,2,4,8,8,2,
  4,4,2,4,4,4,4,4,4,4,4,4,4,4,4,
  4,4,2,4,4,4,4,4,4,4,4,4,4,2,
  4,4,2,4,4,4,4,4,4,4,4,4,4,4,4,
  4,4,2,4,4,4,4,4,4,4,4,4,4,2,
};


void setup() {
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote <178; thisNote++) {

    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
  }
}

void loop() {
  // no need to repeat the melody.
}
