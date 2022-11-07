#ifndef buzzer_included
#define buzzer_included
#define D6 1175
#define D5 587

extern char play_song;
extern int notes[43];
extern int note_duration[43];
extern int delay_time[43];

void buzzer_init();
void buzzer_set_period(short cycles);

#endif
