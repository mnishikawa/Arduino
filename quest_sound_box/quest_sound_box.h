#include <avr/pgmspace.h>

#define MELODY_NUM 8
#define MAX_MELODY_NOTES 512


// tone number
const uint16_t notenum[MELODY_NUM] PROGMEM = {
  //Melody #0 : no melody
  0,
    
  //Melody #1 : Field1
  124,

  //Melody #2 : Fight1
  186,
//  210,

  //Melody #3 : anpan3
  24,
  
  //Melody #4 : anpan4
  48,
  
  //Melody #5 : melody test
  9,

  //Melody #6 : level up
  12,

  //Melody #7 : no melody
  0
};


// notes in the melody:
const uint16_t melody[MELODY_NUM][MAX_MELODY_NOTES] PROGMEM = {

  //Melody #0 : no melody
  {},
  
  //Melody #1 : Field1
  {NOTE_E4, NOTE_E4, NOTE_E4,  
   NOTE_A4, 0, NOTE_B4, NOTE_C5, NOTE_B4, 0, NOTE_C5, NOTE_D5, 
   NOTE_C5, 0, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_E4, 0, NOTE_E4,
   NOTE_A4, NOTE_CS5, NOTE_E5, NOTE_G5, NOTE_G5, NOTE_F5, NOTE_E5, 
   NOTE_D5, 0, NOTE_D5, NOTE_D5, NOTE_E5, 
   NOTE_F5, 0, NOTE_B4, NOTE_E5, NOTE_D5, 
   NOTE_C5, 0, NOTE_C5, NOTE_C5, NOTE_E5, 
   NOTE_D5, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_C5, 
   NOTE_C5, NOTE_B4, NOTE_E5, 

   NOTE_F5, 0, NOTE_A4,
   NOTE_B4, 0, 0, NOTE_A5, NOTE_G5, 0, NOTE_F5,
   NOTE_E5, 0, NOTE_G4,
   NOTE_A4, 0, 0, NOTE_B4, NOTE_C5, 0, NOTE_D5, 
   
   NOTE_E5, NOTE_C5, NOTE_C5, NOTE_D5, 0, NOTE_C5, NOTE_E5, NOTE_C5, NOTE_C5, NOTE_D5, 0, NOTE_C5,
   NOTE_E5, NOTE_C5, NOTE_C5, NOTE_D5, 0, NOTE_C5, NOTE_A5, NOTE_C5, NOTE_C5, NOTE_D5, 0, NOTE_C5, 

   NOTE_C5, 0, NOTE_C5, NOTE_B4, NOTE_B4, 0, NOTE_B4, NOTE_A4, 
   NOTE_A4, 0, NOTE_A4, NOTE_G4, NOTE_G4, 0, NOTE_G4, NOTE_F4, 
   NOTE_E4, 0, NOTE_E4, NOTE_E4, NOTE_E4, 0, NOTE_E4, NOTE_E4, 
   NOTE_E4, 0, NOTE_E4, NOTE_E4, NOTE_E4, 0,
   },
   
  //Melody #2 : Fight1
  {
//   NOTE_F6, NOTE_E6, NOTE_DS6, NOTE_D6, NOTE_CS6, NOTE_C6, 
//   NOTE_B5, NOTE_AS5, NOTE_A5, NOTE_GS5, NOTE_G5, NOTE_FS5,
//   NOTE_F5, NOTE_E5, NOTE_DS5, NOTE_D5, NOTE_CS5, NOTE_C5, 
//   NOTE_B4, NOTE_AS4, NOTE_A4, NOTE_GS4, NOTE_G4, NOTE_FS4,
   
   NOTE_FS3, NOTE_GS3, NOTE_FS3, NOTE_GS3, NOTE_FS3, NOTE_GS3, NOTE_FS3, NOTE_GS3, 
   NOTE_FS3, NOTE_GS3, NOTE_FS3, NOTE_GS3, NOTE_FS3, NOTE_GS3, NOTE_FS3, NOTE_GS3, 
   
   NOTE_F4, NOTE_C5, 
   NOTE_B4, 0, NOTE_G4, NOTE_GS4, NOTE_A4,
   NOTE_AS4, 
   0, 
   NOTE_F4, NOTE_C5, 
   NOTE_B4, 0, NOTE_G4, NOTE_GS4, NOTE_A4,
   NOTE_AS4, 
   0,
    
   NOTE_C6, NOTE_C5, NOTE_C6, NOTE_C5, NOTE_C6, NOTE_C6, NOTE_C5, NOTE_C6, NOTE_C5, NOTE_C6, NOTE_C5, NOTE_FS4, NOTE_E4, NOTE_C4,    
   NOTE_C6, NOTE_C5, NOTE_C6, NOTE_C5, NOTE_C6, NOTE_C6, NOTE_C5, NOTE_C6, NOTE_C5, NOTE_C6, NOTE_C5, NOTE_FS4, NOTE_E4, NOTE_C4,    
   
   NOTE_F4, NOTE_C5, NOTE_B4, 0, NOTE_G4, 0, NOTE_AS4, 0, NOTE_F4, NOTE_FS4, NOTE_G4, NOTE_E4,   
   NOTE_F4, NOTE_C5, NOTE_B4, 0, NOTE_G4, 0, NOTE_AS4, 0, NOTE_F4, NOTE_FS4, NOTE_G4, NOTE_E4,   
   
   NOTE_F5, NOTE_F4, NOTE_F5, NOTE_F4, NOTE_F5, NOTE_E5, NOTE_E4, NOTE_E5, NOTE_E4, NOTE_E5, NOTE_DS5, NOTE_DS4, NOTE_DS5, NOTE_DS4,    
   NOTE_DS5, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, 
   NOTE_F5, NOTE_F4, NOTE_F5, NOTE_F4, NOTE_F5, NOTE_E5, NOTE_E4, NOTE_E5, NOTE_E4, NOTE_E5, NOTE_DS5, NOTE_DS4, NOTE_DS5, NOTE_DS4,    
   NOTE_DS5, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, 

   NOTE_F4, NOTE_FS4, NOTE_G4, NOTE_GS4, NOTE_A4, NOTE_AS4, 
   NOTE_B4, NOTE_C5, NOTE_CS5, NOTE_D5, NOTE_DS5, NOTE_E5, 
   NOTE_F5, NOTE_FS5, NOTE_G5, NOTE_GS5, NOTE_A5, NOTE_AS5, 
   NOTE_B5, NOTE_C6, NOTE_CS6, NOTE_D6, NOTE_DS6, NOTE_E6, 

   NOTE_F6, NOTE_E6, NOTE_DS6, NOTE_D6, NOTE_CS6, NOTE_C6, 
   NOTE_B5, NOTE_AS5, NOTE_A5, NOTE_GS5, NOTE_G5, NOTE_FS5,
   NOTE_F5, NOTE_E5, NOTE_DS5, NOTE_D5, NOTE_CS5, NOTE_C5, 
   NOTE_B4, NOTE_AS4, NOTE_A4, NOTE_GS4, NOTE_G4, NOTE_FS4, 
   
   
   
   
   },

  //Melody #3 : anpan3
  {NOTE_F4, NOTE_G4, NOTE_F4, 0, NOTE_F4, NOTE_G4, NOTE_F4, 0,
   NOTE_F4, 0, NOTE_AS4, 0, NOTE_F4, 0, NOTE_D5, 0,
   NOTE_C5, 0, NOTE_G4, 0, NOTE_A4, 0, NOTE_G4,
   NOTE_F4},
   
  //Melody #4 : anpan4
  {NOTE_D5, 0, NOTE_D5, 0, NOTE_AS4, 0,
   NOTE_G4, 0, NOTE_G4, NOTE_A4, NOTE_AS4, 0, NOTE_G4, 0,
   NOTE_C5, 0, NOTE_D5, NOTE_C5, 0, NOTE_AS4, 0, 
   NOTE_A4, 0, NOTE_G4, 0, NOTE_F4,
   NOTE_D5, 0, NOTE_D5, 0, NOTE_AS4, 0,
   NOTE_G4, 0, NOTE_G4, NOTE_A4, NOTE_AS4, 0, NOTE_G4, 0,
   NOTE_C5, 0, NOTE_D5, NOTE_C5, 0, NOTE_A4, 0, 
   NOTE_AS4},

  //Melody #5 : melody test
  {0, NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5},

  //Melody #6 : level up
  {0, NOTE_F5, NOTE_F5, NOTE_F5, NOTE_F5, 0, NOTE_DS5, 0, NOTE_G5, 0, NOTE_F5, 0},

  //Melody #7 : no melody
  {}

};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
const uint16_t noteDurations[MELODY_NUM][MAX_MELODY_NOTES] PROGMEM = {
  //Melody #0 : no melody
  {},

  //Melody #1 : Field1
  {12,12,12,
   4,8,16,16,4,8,16,16,
   4,8,16,16,4,8,16,16,
   12,12,12,2,12,12,12,
   2,4,12,12,12,
   2,4,12,12,12,
   2,4,12,12,12,
   4,12,12,12,4,4,
   2,4,4,
   
   2,4,4,
   2,8,16,16,8,16,16,
   2,4,4,
   2,8,16,16,8,16,16,

   12,12,12,8,16,16,12,12,12,8,16,16,   
   12,12,12,8,16,16,12,12,12,8,16,16,

   8,16,16,4,8,16,16,4,
   8,16,16,4,8,16,16,4,
   4,8,16,16,4,8,16,16,
   4,8,16,16,2,4,
   },

  //Melody #2 : Fight1
  {
//   24,24,24,24,24,24,
//   24,24,24,24,24,24,
//   24,24,24,24,24,24,
//   24,24,24,24,24,24,
   
   8,8,8,8,8,8,8,8, 
   8,8,8,8,8,8,8,8, 
   
   2,2,
   2,4,8,16,16,
   1,
   1,
   2,2,
   2,4,8,16,16,
   1,
   1,
   
   16,16,16,16,8,16,16,16,16,8,16,16,16,16, 
   16,16,16,16,8,16,16,16,16,8,16,16,16,16, 


   4,8,8,8,8,8,2,4,16,16,8,8,
   4,8,8,8,8,8,2,4,16,16,8,8,
   
   16,16,16,16,8,16,16,16,16,8,16,16,16,16, 
   8,16,16,8,16,16,8,16,16,8,16,16,
   16,16,16,16,8,16,16,16,16,8,16,16,16,16, 
   8,16,16,8,16,16,8,16,16,8,16,16,
   
   24,24,24,24,24,24,
   24,24,24,24,24,24,
   24,24,24,24,24,24,
   24,24,24,24,24,24,

   24,24,24,24,24,24,
   24,24,24,24,24,24,
   24,24,24,24,24,24,
   24,24,24,24,24,24,
   },

  //Melody #3 : anpan3
  {8,8,8,8,8,8,8,8,
   8,8,8,8,8,8,8,8,
   8,8,8,8,4,8,8,
   1},

  //Melody #4 : anpan4
  {8,8,8,8,4,4,
   8,8,8,8,8,8,8,8,
   4,8,8,8,8,8,8,
   8,8,8,8,2,
   8,8,8,8,4,4,
   8,8,8,8,8,8,8,8,
   4,8,8,8,8,8,8,
   1},

  //Melody #5 : melody test
  {4, 8, 8, 8, 8, 8, 8, 8, 2},

  //Melody #6 : level up
  {8, 10, 10, 10,
   8, 8, 8, 8, 8, 8,
   2,2},

  //Melody #7 : no melody
  {}

};
