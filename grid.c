#include "grid.h"
#include "stdint.h"
#include "stdio.h"

#define WIDTH 10
#define HEIGHT 10

#define RED 0x00200000   // 0xWWRRGGBB
#define BLUE 0x00000020
#define GREEN 0x00002000
#define YELLOW 0x00202000
#define WHITE 0x00202020
#define PINK 0x00FF33FF

static char leds[100];
int numberGuesses = 0;

void initialiseMatrix(void) {
    for (int i = 0; i < 100; i++) {
        leds[i] = '-';
    }
}

void setScore(int blackScore, int whiteScore) {
    copyUpRows(0);
    copyUpRows(6);
    for (int i = 0; i < 4; i++) {
        leds[9 * 10 + 6 + i] = '-';
    }

    int index = 0;
    for (int i = 0; i < blackScore; i++) {
        leds[8 * 10 + index] = 'p';
        index++;
    }
    for (int i = 0; i < whiteScore; i++) {
        leds[8 * 10 + index] = 'w';
        index++;
    }

}

void copyUpRows(int index) {
    for (int j = 0; j < 9; j++) {
        for (int i = 0; i < 4; i++) {
            leds[j * 10 + i + index] = leds[(j + 1) * 10 + i + index];
        }
    }
}

void setGuess(int index, char chr) {
    leds[9 * 10 + 6 + index] = chr;
}

void printMatrix(ws2811_t *ledString) {
    printf("\033[0;31m");
    for (int i = 0; i < 100; i++) {
        if (i % 10 == 9) {
            printf("%c\n\n", leds[i]);
        } else {
            printf("%c ", leds[i]);
        }
        switch (leds[i]) {
            case 'r':
                ledString->channel[0].leds[i] = RED;
                break;
            case 'b':
                ledString->channel[0].leds[i] = BLUE;
                break;
            case 'g':
                ledString->channel[0].leds[i] = GREEN;
                break;
            case 'y':
                ledString->channel[0].leds[i] = YELLOW;
                break;
            case 'p':
                ledString->channel[0].leds[i] = PINK;
                break;
            case 'w':
                ledString->channel[0].leds[i] = WHITE;
                break;
        }
    }
    printf("\033[0m");
    for (int i = 0; i < 50; i++) {
        printf("%c", '_');
    }
    printf("\n");
}
