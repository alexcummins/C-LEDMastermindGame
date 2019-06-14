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

        // Account for alternating rows on the LED grid
        int pos = 0;
        if (i % 20 > 9){
            pos = 9 - (i % 10);
        }
        else {
            pos = i;
        }
        switch (leds[i]) {
            case 'r':
                ledString->channel[0].leds[pos] = RED;
                break;
            case 'b':
                ledString->channel[0].leds[pos] = BLUE;
                break;
            case 'g':
                ledString->channel[0].leds[pos] = GREEN;
                break;
            case 'y':
                ledString->channel[0].leds[pos] = YELLOW;
                break;
            case 'p':
                ledString->channel[0].leds[pos] = PINK;
                break;
            case 'w':
                ledString->channel[0].leds[pos] = WHITE;
                break;
        }
    }
    printf("\033[0m");
    for (int i = 0; i < 50; i++) {
        printf("%c", '_');
    }
    printf("\n");
    ws2811_return_t ret;
    if ((ret = ws2811_render(ledString)) != WS2811_SUCCESS) {
        fprintf(stderr, "ws2811_render failed: %s\n", ws2811_get_return_t_str(ret));
    }
}
