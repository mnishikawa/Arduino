#define MELODY_NUM 8
#define MAX_MELODY_NOTES 48


// tone number
int notenum[MELODY_NUM]= {
  //Melody #0 : no melody
  0,
    
  //Melody #1 : anpan1
  47,

  //Melody #2 : anpan2
  26,

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
const int melody[MELODY_NUM][MAX_MELODY_NOTES] = {

  //Melody #0 : no melody
  {},
  
  //Melody #1 : anpan1
  {NOTE_AS3, NOTE_C4, NOTE_D4, NOTE_DS4, NOTE_F4, 0, NOTE_AS4, 0, 
   NOTE_G4, NOTE_F4, NOTE_DS4, NOTE_F4,
   NOTE_DS4, NOTE_D4, NOTE_C4, NOTE_D4, 0, NOTE_AS3,0,
   NOTE_C4,0,NOTE_D4,NOTE_C4, 0,
   NOTE_AS3, NOTE_C4, NOTE_D4, NOTE_DS4, NOTE_F4, 0, NOTE_AS4, 0, 
   NOTE_G4, NOTE_F4, NOTE_DS4, NOTE_F4,
   NOTE_DS4, NOTE_D4, NOTE_C4, NOTE_D4, 0, NOTE_AS3,0,
   NOTE_C4,0,NOTE_F4,NOTE_AS3},
   
  //Melody #2 : anpan2
  {NOTE_C4, NOTE_D4, NOTE_C4, 0, NOTE_C4, NOTE_D4, NOTE_C4, 0,
   NOTE_C4, 0, NOTE_F4, 0, NOTE_C4,
   NOTE_D4, NOTE_DS4, NOTE_D4, 0, NOTE_D4, NOTE_DS4, NOTE_D4, 0,
   NOTE_D4, 0, NOTE_G4, 0, NOTE_D4},

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
int noteDurations[MELODY_NUM][MAX_MELODY_NOTES] = {
  //Melody #0 : no melody
  {},

  //Melody #1 : anpan1
  {8,8,8,8,8,8,8,8,
   4,8,8,2,
   4,8,8,8,8,8,8,
   4,8,8,4,4,
   8,8,8,8,8,8,8,8,
   4,8,8,2,
   4,8,8,8,8,8,8,
   4,8,8,2},

  //Melody #2 : anpan2
  {8,8,8,8,8,8,8,8,
   8,8,8,8,2,
   8,8,8,8,8,8,8,8,
   8,8,8,8,2},

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
