#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include "grid.h"
#include "mastermind.h"


int runGame(ws2811_t *ledString) {

    initialiseMatrix();
    printMatrix(ledString);
//    bool another;

    char code[4] = {'r', 'b', 'g', 'y'};


    char guess[4];
    readGuess(guess);
    setScore(blackScore(guess, code), whiteScore(guess, code));
    int guessCount = 1;
    while (blackScore(guess, code) != 4 && guessCount < 9) {
        readGuess(guess);
        printMatrix(ledString);
        setScore(blackScore(guess, code), whiteScore(guess, code));
        printMatrix(ledString);
        guessCount++;
    }
    if (guessCount < 9) {
        printf("You have guessed correctly!\n");
    } else {
        printf("You have run out of guesses\n");
    }


    return 0;
}

bool anotherGame(void) {
    char answer;
    printf("Do you want to play another game? [y/n]: ");
    if (!scanf("%*c%c", &answer)) {
        printf("Failed to read answer");
    }
    return answer == 'y';
}

void clearBuffer() {
    char c;
    while ((c = getchar()) != '\n');
}

void readGuess(char *guess) {
    printf("Enter your guess: ");

    for (int i = 0; i < 4; i++) {
        do {
            if (!scanf("%c", &guess[i])) {
                printf("Failed to read answer");
            }
            clearBuffer();
        } while (!strchr("rgyb", guess[i]));
        setGuess(i, guess[i]);
    }

}

int blackScore(char guess[4], char code[4]) {
    int score = 0;


    for (int i = 0; i < 4; i++) {
        if (code[i] == guess[i]) {
            score++;
        }
    }

    return score;
}

int whiteScore(char *guess, char *code) {
    int score = 0;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if ((i != j) && (code[i] == guess[j])) {
                score++;
            }
        }
    }

    return score;
}

void printScore(char *g, char *c) {
    printf("(%d, %d)\n",
           blackScore(g, c),
           whiteScore(g, c));
}
