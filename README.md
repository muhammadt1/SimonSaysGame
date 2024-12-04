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
- The STM and breadboard must me configured as per the [Schematic](SimonSaysSchematic.pdf).

- Once the breadboard and STM are setup accordingly, the main program must be loaded onto the STM initate the game. This will then begin the starting sequence of the game.

### Game Instructions
1) While the knight rider sequence is running, press any of the 4 buttons to start the rounds.
2) Follow the round by round pattern until level 10 is reached (winning sequence).
3) Failure to press correct button OR taking too long to press a button results in losing the game (failure sequence)
