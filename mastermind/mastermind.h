#ifndef CEXTENSIONPROJECT_RPI_WS281X_FORK_MASTERMIND_H
#define CEXTENSIONPROJECT_RPI_WS281X_FORK_MASTERMIND_H

#include "../ws2811.h"
#include <stdbool.h>

void runGame(ws2811_t *ledString);

bool anotherGame(void);

void readGuess(char *guess, ws2811_t *ledString);

void score(char guess[4], char code[4], int *blackScore, int *whiteScore);

int charToIndex(char chr);

void clearBuffer(void);

#endif //CEXTENSIONPROJECT_RPI_WS281X_FORK_MASTERMIND_H
