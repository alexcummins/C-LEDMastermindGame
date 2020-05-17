# LED Mastermind Game

Code to play a game of Mastermind [Wikipedia](https://en.wikipedia.org/wiki/Mastermind_(board_game)) on a 10x10 WS2811 RGB LED grid.

Library is set up to accomodate my 10x10 WS2811 RGB LED grid.
Main calls runGame from import mastermind.h passing in the ledstring to be updated.
All game logic is in Mastermind folder, the rest is code to update the LED grid from the [ws281x](https://github.com/jgarff/rpi_ws281x) repository.

List of games:
- Mastermind

Files we changed are in Mastermind folder, as well as main.c, and the SConscript.
There is also an incomplete start at making a game of snake in Snake folder.

## Getting Started

My LED grid is run with a raspberry Pi, which can be set up by following the Adafruit Neopixel (tutorial)[https://learn.adafruit.com/neopixels-on-raspberry-pi]. Attributes of the LED grid such as width and height are constants in main.c. This code is intended to be run on the Raspberry Pi in the terminal, with the game grid displayed on the LED matrix.


### Prerequisites

Follow the adafruit guide to get the LEDs set up, then it should work if you have the same LEDs. Watch out for RGB vs GRB or RGBW Led types. Can modify main.c constants at top of file to account for these.

