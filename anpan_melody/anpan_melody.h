#define MELODY_NUM 8
#define MAX_MELODY_NOTES 32


// tone number
int notenum[MELODY_NUM]= {
  //Melody #0 : hogehoge0
  8,
    
  //Melody #1 : hogehoge1
  16,

  //Melody #2 : hogehoge2
  16,

  //Melody #3 : hogehoge3
  24,
  
  //Melody #4 : hogehoge4
  32,
  
  //Melody #5 : hogehoge5
  32,

  //Melody #6 : hogehoge6
  32,

  //Melody #7 : hogehoge7
  32    
};


// notes in the melody:
int melody[MELODY_NUM][MAX_MELODY_NOTES] = {

  //Melody #0 : hogehoge0
  {NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4},
  
  //Melody #1 : hogehoge1
  {NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_B0,
   NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_B0},

  //Melody #2 : hogehoge2
  {NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_D1,
   NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_D1},

  //Melody #3 : hogehoge3
  {NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_F2,
   NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_F2,
   NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_F2},

  //Melody #4 : hogehoge4
  {NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_E3,
   NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_E3,
   NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_E3,
   NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_E3},

  //Melody #5 : hogehoge5
  {NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_G3,
   NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_G3,
   NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_G3,
   NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_G3},

  //Melody #6 : hogehoge6
  {NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_A3,
   NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_A3,
   NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_A3,
   NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_A3},

  //Melody #7 : hogehoge7
  {NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_D8,
   NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_D8,
   NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_D8,
   NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_D8}

};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[MELODY_NUM][MAX_MELODY_NOTES] = {
  //Melody #0 : hogehoge0
  {4, 8, 8, 4, 4, 4, 4, 4},

  //Melody #1 : hogehoge1
  {4, 8, 8, 4, 4, 4, 4, 4,
   4, 8, 8, 4, 4, 4, 4, 4},

  //Melody #2 : hogehoge2
  {4, 8, 8, 4, 4, 4, 4, 4,
   4, 8, 8, 4, 4, 4, 4, 4},

  //Melody #3 : hogehoge3
  {4, 8, 8, 4, 4, 4, 4, 4,
   4, 8, 8, 4, 4, 4, 4, 4,
   4, 8, 8, 4, 4, 4, 4, 4},

  //Melody #4 : hogehoge4
  {4, 8, 8, 4, 4, 4, 4, 4,
   4, 8, 8, 4, 4, 4, 4, 4,
   4, 8, 8, 4, 4, 4, 4, 4,
   4, 8, 8, 4, 4, 4, 4, 4},

  //Melody #5 : hogehoge5
  {4, 8, 8, 4, 4, 4, 4, 4,
   4, 8, 8, 4, 4, 4, 4, 4,
   4, 8, 8, 4, 4, 4, 4, 4,
   4, 8, 8, 4, 4, 4, 4, 4},

  //Melody #6 : hogehoge6
  {4, 8, 8, 4, 4, 4, 4, 4,
   4, 8, 8, 4, 4, 4, 4, 4,
   4, 8, 8, 4, 4, 4, 4, 4,
   4, 8, 8, 4, 4, 4, 4, 4},

  //Melody #7 : hogehoge7
  {4, 8, 8, 4, 4, 4, 4, 4,
   4, 8, 8, 4, 4, 4, 4, 4,
   4, 8, 8, 4, 4, 4, 4, 4,
   4, 8, 8, 4, 4, 4, 4, 4}

};
