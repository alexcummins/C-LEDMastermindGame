#ifndef EXTENSION_GRID_H
#define EXTENSION_GRID_H

#include "ws2811.h"

void initialiseMatrix(void);
void copyUpRows(int index);
void setGuess(int index, char chr);
void setScore(int blackScore, int whiteScore);
void printMatrix(ws2811_t *ledString);

#endif //EXTENSION_GRID_H
