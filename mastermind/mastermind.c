#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include "grid.h"
#include "mastermind.h"
#include <time.h>
#include <stdlib.h>
#include <ctype.h>


void runGame(ws2811_t *ledString) {

    initialiseMatrix();
    displayMatrix(ledString);


    bool playAgain = true;
    while (playAgain){

        initialiseMatrix();
        displayMatrix(ledString);
        char code[4];

        srand(time(NULL));
        int r;

        for (int i = 0; i < 4; i++) {
            r = rand() % 4;
            switch (r) {
                case 0:
                    code[i] = 'r';
                    break;
                case 1:
                    code[i] = 'g';
                    break;
                case 2:
                    code[i] = 'y';
                    break;
                case 3:
                    code[i] = 'b';
                    break;
            }
            printf("%c", code[i]);
        }
        printf("\n");

        int blackScore = 0;
        int whiteScore = 0;
        char guess[4];

        readGuess(guess,ledString);
        score(guess, code, &blackScore, &whiteScore);
        setScore(blackScore, whiteScore);
        displayMatrix(ledString);
        int guessCount = 1;
        while (blackScore != 4 && guessCount < 9) {
            readGuess(guess,ledString);
            displayMatrix(ledString);
            score(guess, code, &blackScore, &whiteScore);
            setScore(blackScore, whiteScore);
            displayMatrix(ledString);
            guessCount++;
        }
        if (guessCount < 9) {
            printf("You have guessed correctly!\n");
        } else {
            printf("You have run out of guesses\n");
        }
        playAgain = anotherGame();
    }
}

bool anotherGame(void) {
    char answer;
    printf("Do you want to play another game? [y/n]: ");
    scanf("%c", &answer);
    answer = tolower(answer);
    clearBuffer();
    return answer == 'y';
}

void clearBuffer(void) {
    char c;
    while ((c = getchar()) != '\n');
}

void readGuess(char *guess, ws2811_t *ledString) {
    printf("Enter your guess: ");

    for (int i = 0; i < 4; i++) {
        do {
            if (!scanf("%c", &guess[i])) {
                printf("Failed to read answer");
            }
            clearBuffer();
        } while (!strchr("rgyb", guess[i]));
        setGuess(i, guess[i]);
        displayMatrix(ledString);
    }

}

void score(char guess[4], char code[4], int *blackScore, int *whiteScore) {
    *blackScore = 0;
    *whiteScore = 0;
    int correctPosition[4] = {0, 0, 0, 0};
    int colourFrequency[4] = {0, 0, 0, 0};

    for (int i = 0; i < 4; i++) {
        colourFrequency[charToIndex(code[i])]++;
        if (guess[i] == code[i]){
            (*blackScore)++;
            colourFrequency[charToIndex(guess[i])]--;
            correctPosition[charToIndex(guess[i])] = 1;
        }
    }

    for (int i = 0; i < 4; i++){
        if(!correctPosition[i] && colourFrequency[charToIndex(guess[i])] > 0){
            (*whiteScore)++;
            colourFrequency[charToIndex(guess[i])]--;
        }


    }
}

int charToIndex(char chr) {
    switch (chr) {
        case 'r':
            return 0;
        case 'y':
            return 1;
        case 'g':
            return 2;
        case 'b':
            return 3;
        default:
            assert(false);
            return 0;
    }
}
