#ifndef CEXTENSIONPROJECT_RPI_WS281X_FORK_MASTERMIND_H
#define CEXTENSIONPROJECT_RPI_WS281X_FORK_MASTERMIND_H

#include "../ws2811.h"
#include <stdbool.h>

int runGame(ws2811_t *ledString);

bool anotherGame(void);

void readGuess(char *guess);

int blackScore(char guess[4], char code[4]);

int whiteScore(char guess[4], char code[4]);

void printScore(char g[], char c[]);


#endif //CEXTENSIONPROJECT_RPI_WS281X_FORK_MASTERMIND_H
