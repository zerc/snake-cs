#include <curses.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    initscr();                 /* Start curses mode 		  */
    printw("Hello World !!!"); /* Print Hello World		  */
    refresh();                 /* Print it on to the real screen */
    getch();                   /* Wait for user input */
    endwin();                  /* End curses mode		  */

    return EXIT_SUCCESS;
}
