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
<b>Starting Sequence</b>
- The game begins with the knight rider sequence.
- This sequence turns on 1 LED at a time and goes back and fourth across all 4 of the LED's.
- The rounds begin once any of the four push buttons have been pushed.

<b>Game Rounds</b>
