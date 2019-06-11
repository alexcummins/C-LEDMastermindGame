#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>
#include <time.h>
#include <ncurses.h>

/* build with:
 * gcc -static main.c -o test -lncurses -ltinfo
*/

int main(){
    initscr();
    cbreak();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE); // means input will return ERR if key input not done.

    clear();

    int ch, oldch;
    ch = KEY_UP;
    while(1){
        oldch = ch;
        if ((ch = getch()) == ERR){
            ch = oldch;
        }
        // could do switch on ch
        if (ch == KEY_UP) {
            mvprintw(0, 0, "Key up!\n");
        }
        if (ch == KEY_DOWN) {
            mvprintw(0, 0, "Key down!\n");
        }
        if (ch == KEY_LEFT) {
            mvprintw(0, 0, "Key left!\n");
        }
        if (ch == KEY_RIGHT) {
            mvprintw(0, 0, "Key right!\n");
        }
        if (ch == KEY_BACKSPACE){
            break;
        }
    }
    printf("Done.");
    endwin();
}
