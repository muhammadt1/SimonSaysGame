#include "stm32f10x.h"
#include "main.h"
#include <stdlib.h>






int main() {
	while(1){
		
		//array storing sequence for LED patterns
		int pattern[gameRounds];        
		int current_round = 0;           
    unsigned int seed = 0;           
    unsigned int currentStage = 0;  
		
		initilization();		//initalizes hardware
		seed = waitStart(); //seed to wait for player to begin.
			
		while (current_round < gameRounds) {
			pattern[current_round] = randomNumberTo4(seed); 	//generates random pattern and outputs
      patternDisplay(pattern, current_round); //displays said pattern
			currentStage = buttonCheck(pattern, current_round); //check for player input being correct.
			delay(1000); //1 second delay
			
			//player lost
			if (currentStage == 0) {
				gameOver();  //losing sequence runs                 
        binaryResult(current_round); //displays round
                
				while(!activeButtonCheck()){
					//waiting for button press
				}
				delay(200); //double press checker
				break;                      
			}
			
			current_round++; //moves onto the next round
      seed = currentStage; //new seed
		}
				
		// player won
		if (current_round == gameRounds) {
			gameWon();    //winning sequence
			binaryResult(gameRounds); //displays round
			while(!activeButtonCheck()){
				//waiting for button press
			}
			delay(200);                  
		}
   }

}

/*
	function Declarations
*/
void LED1On(){
	GPIOA->ODR |= (1 << 0); 
}

void LED2On(){ 
	GPIOA->ODR |= (1 << 1); 
}
void LED3On(){ 
	GPIOA->ODR |= (1 << 4); 
}
void LED4On(){ 
	GPIOB->ODR |= (1 << 0); 
}

void LED1Off(){ 
	GPIOA->ODR &= ~(1 << 0); 
}
void LED2Off(){ 
	GPIOA->ODR &= ~(1 << 1); 
}
void LED3Off(){ 
	GPIOA->ODR &= ~(1 << 4); 
}

void LED4Off(){ 
	GPIOB->ODR &= ~(1 << 0); 
}


void initilization() {
	//clock enables for GPIOA and GPIOB
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPBEN;
  GPIOA->CRL = 0x00030033;	//GPIOA low registers 
	GPIOB->CRL = 0x04440003;	//GPIOB low registers
  GPIOB->CRH = 0x00000044;	//GPIOB high registers
}

void delay(int time) {
	int i, j;
  for(i = 0; i < time; i++){
		for(j = 0; j < time; j++){
		
		}
	}
}

void all_leds_off() {
	LED1Off();
	LED2Off();
	LED3Off();
  LED4Off();
}

void all_leds_on() {
	LED1On();
	LED2On();
	LED3On();
	LED4On();
}

/*
	waiting for player to begin the game.

*/

unsigned int waitStart() {
	unsigned int count = 0;
  int started = 0;
	
	//knight rider
	while (!started) {
		LED1On(); 	//led 1 turns on
		delay(750); //0.75sec delay
		LED1Off();
		
		if (activeButtonCheck()) {
			started = 1;
      break;
		}
		LED2On();   // second led
		delay(750);
    LED2Off();
		
		if (activeButtonCheck()) {
			started = 1;
      break;
		}
		LED3On(); // third led
    delay(750); 
    LED3Off();
		
		if (activeButtonCheck()) {
			started = 1;
			break;
		}
 
    LED4On(); //fourth led
    delay(750);
		LED4Off();
		if (activeButtonCheck()) {
			started = 1;
			break;
		}
		
		//backwards
		LED3On();
    delay(750);
    LED3Off();
		
		if (activeButtonCheck()){
			started = 1;
      break;
		}
        
        
		LED2On();
    delay(750);
    LED2Off();
		
		if (activeButtonCheck()){
			started = 1;
      break;
		}
		
		count++;
	}
	
	all_leds_on();
  delay(1100);
  all_leds_off();
  delay(1100);
    
  return count;
}

int randomNumberTo4(unsigned int seed) {
	int limit;
  int r;
  srand(seed);
	
  limit = RAND_MAX - (RAND_MAX % numLeds);
    
  while ((r = rand()) >= limit);
    
  return r % numLeds;
}

void patternDisplay(int *pattern, int size) {
	//shows pattern sequences.
	//turns on appropriate led based on pattern
	//1 second on. 1 second off
	for (int i = 0; i <= size; i++) {
		all_leds_off();
		
    if (pattern[i] == 0)
		{
			LED1On();
		}
		else if (pattern[i] == 1)
		{
			 LED2On();
		}
		else if (pattern[i] == 2)
		{
			 LED3On();
		}
		else if (pattern[i] == 3)
		{
			 LED4On();
		}
		
		delay(1000);
    all_leds_off();
    delay(1000);
	}
}

unsigned int buttonCheck(int *pattern, int size) {
	//check players button to see if it matches pattern.
	//5 second time given to user.
	unsigned int seed = 0;
  int i = 0;
  int correct = 0;
	
	while (i <= size && correct == i) {
		unsigned int time_left = 500000; //5sec
		while (time_left > 0) {
			seed += 10;
      delay(12);
      time_left -= 10;
			
			if ((GPIOB->IDR & (1 << 4)) == 0){
				LED1On();
				if (pattern[i] == 0){
					correct++;
				}
				else {
					return 0;
				}
        delay(500);
				all_leds_off();
        delay(800);
        break;
			}
			if ((GPIOB->IDR & (1 << 6)) == 0) {
				LED2On();
        if (pattern[i] == 1) {
					correct++;
				}
				else{
					return 0;
				}
				delay(500);
        all_leds_off();
        delay(800);
				break;
			}
			if ((GPIOB->IDR & (1 << 8)) == 0) {
				LED3On();
        if (pattern[i] == 2) 
				{
					correct++;
				}
        else{
					return 0;
				}  
				delay (500);
				all_leds_off();
				delay(800);
				break;
			}
			if ((GPIOB->IDR & (1 << 9)) == 0) {
				LED4On();
				if (pattern[i] == 3){
					correct++;
				}
				else{
					return 0;
				}
				delay(500);
        all_leds_off();
        delay(800);
				break;
			}
		}
		if (time_left <= 0){
			return 0;
		}
		i++;
	}
		if (correct == i) {
				return seed;
		} else {
				return 0;
		}


}

void gameOver() {
  for(int i = 0; i < 4; i++) {
		all_leds_on();
    delay(850);//0.85 seconds on
		all_leds_off();
		delay(850); //0.85 second off
	}
}

void gameWon() {
	for(int i = 0; i < 4; i++) {
		all_leds_on();
    delay(1500); //1.5 second on
		all_leds_off();
		delay(1500);//1.5 second off
	}
}

void binaryResult(int score) {
	//displays score 1-10, using binary values on the LEDs
	all_leds_off();
	switch(score) {
		case 1:
			LED1On();
      break;
		case 2:
      LED2On();
      break;
		case 3:
			LED1On();
      LED2On();
      break;
		case 4:
			LED3On();
      break;
		case 5:
			LED1On();
      LED3On();
			break;
    case 6:
			LED2On();
      LED3On();
			break;
		case 7:
			LED1On();
			LED2On();
			LED3On();
      break;
		case 8:
			LED4On();
			break;
		case 9:
			LED1On();
      LED4On();
      break;      
    case 10:
			LED2On();
			LED4On();
			break;
	}
}

int activeButtonCheck() {
	//checks if any button is pressed.
	//returns 1 if pressed.
	//reads from GPIOB IDR
	int button1 = GPIOB->IDR & (1 << 4);  
  int button2 = GPIOB->IDR & (1 << 6);
  int button3 = GPIOB->IDR & (1 << 8);
  int button4 = GPIOB->IDR & (1 << 9);
    
  if (button1 == 0 || button2 == 0 || button3 == 0 || button4 == 0) {
		return 1;
	}
    
	return 0;
}