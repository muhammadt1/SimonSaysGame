#include "stm32f10x.h"
#include <stdlib.h> 

void LED1On(void);
void LED2On(void); 
void LED3On(void); 
void LED4On(void); 
void LED1Off(void); 
void LED2Off(void); 
void LED3Off(void); 
void LED4Off(void); 
void initilization(void);
void delay(unsigned int time);
void all_leds_off(void);
void all_leds_on(void);
unsigned int waitStart(void);
int randomNumberTo4(unsigned int seed);
void patternDisplay(int *pattern, int size);
unsigned int buttonCheck(int *pattern, int size);
void gameOver(void);
void gameWon(void);
void binaryResult(int score);
int activeButtonCheck(void);
