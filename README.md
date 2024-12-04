# Simon Says
### Description
Simon says is a popular game based off of a toy, in which a randomized pattern is generated at different levels and users must memorize the pattern and input it onto a set of four buttons.

This project recreates the simon says game using the following: 
- STM32F103RB
- Breadboard
- 4 LED's (Red)
- 4 Push buttons
- 270 Ohm Isolated Resistor Network
- 10K Bus Resistor Network.

### Setup
- The STM and breadboard must me configured as per the schematic here.
- Once the breadboard and STM are setup accordingly, the main program must be loaded onto the STM initate the game. This will then begin the starting sequence of the game.

### Game Instructions
<b>Starting Sequence</b>
- The game begins with the knight rider sequence.
- This sequence turns on 1 LED at a time and goes back and fourth across all 4 of the LED's.
- The rounds begin once any of the four push buttons have been pushed.

<b>Game Rounds</b>
- The rounds begin at level 1 and progress all the way to level 10.
- At round 1, one of the LED's will be randomly displayed. It is then the players job to press the appropriate coorelated button to move on to the next level.
- As the game progresses, the levels remember the pattern of the previous levels and the user must get it fully correct until level 10 to win the game.

- For example:
1) Level 1 Outputs any of the 4 LED's
2) Level 2 Outputs the same LED from level 1, aswell as another random LED for level 2.
3) Level 3 Outputs the LED's from level 1 and 2, aswell as the new LED for level 3.

This will continue until the player reaches level 10 OR will run the failure sequence if the player fails to follow the pattern.