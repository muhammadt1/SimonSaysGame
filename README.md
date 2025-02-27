# Simon Says
### Description
Simon says is a popular game based off of a toy, in which a randomized pattern is generated at different levels and users must memorize the pattern and input it onto a set of four buttons.

<b>Project Demonstration:</b> https://youtu.be/QaUWFxio2hI


This project recreates the simon says game using the following 
- STM32F103RB
- Breadboard
- 4 LED's (Red)
- 4 Push buttons
- 270 Ohm Isolated Resistor Network
- 10K Bus Resistor Network.   `

### Circuit Setup
- The STM and breadboard must me configured as per the schematic [here](SimonSaysSchematic.pdf).
- Once the breadboard and STM are setup accordingly, the main program must be loaded onto the STM initate the game. This will then begin the starting sequence of the game.
- The black button on the STM can be used initiate the code to begin the code execution.
- This button can be used at anytime to reset the overall program.


### Game Instructions
1) While the knight rider sequence is running, press any of the 4 buttons to start the rounds. All 4 lights will blink once indicating that the rounds have began.
2) Follow the round by round pattern until level 10 is reached (winning sequence). If level 10 is reached, the code should output 10 in binary using the LED's (1010).
3) Failure to press correct button OR taking too long to press a button results in losing the game (losing sequence). The code then outputs the score achieved by the user. Ex) At level 3 if a failure occurs, the outputted result will show the score achieved, in this case it would be 2 (0010).

### Sequences
Winning Sequence
- All four LEDs blink simultaneously 4 times (1.5s on, 1.5s off)
- Displays after completing all 10 levels.
- Outputs 10 in binary (1010)

Losing Sequence 
- All four LEDs blink simultaneously 4 times (0.85s on, 0.85s off)
- Shows when player fails pattern or exceeds 5s time limit
- Outputs score achieved by player. Ex) If a player messes up at level 3, it will output a score of 2 (0100)