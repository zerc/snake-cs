#include <curses.h>
#include <stdlib.h>

#include "sn_options.h"

int main(int argc, char *argv[])
{
    int error = 0;
    SN_Options options = sn_parse_options(argc, argv, &error);

    if (error != 0)
    {
        print_error("Could not parse CLI parameters.");
        return EXIT_FAILURE;
    }

    puts("Options\n");
    printf("show_version=%d\n", options.show_version);
    printf("show_help=%d\n", options.show_help);
    printf("gui=%d\n", options.gui);
    printf("name=%s\n", options.name);
    printf("connect=%s\n", options.connect);
    puts("\ndone\n");

    return EXIT_SUCCESS;
}