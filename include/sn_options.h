#include <getopt.h>

#ifndef SNAKE_CS_OPTIONS_H
#define SNAKE_CS_OPTIONS_H

enum SN_GUI
{
    gui_none,
    gui_terminal,
    gui_opengl,
};

typedef struct SN_Options SN_Options;
struct SN_Options
{
    int show_version;
    int show_help;
    enum SN_GUI gui;
    char name[20];    // Matches PLAYER_NAME_LENGTH
    char connect[20]; // TODO: parse it into a struct
};

SN_Options sn_parse_options(int argc, char *argv[]);
int sn_parse_long_option(SN_Options *opts, int index);
int sn_parse_short_option(SN_Options *opts, int c);
void sn_set_str_value(char *dest, char *src, int len);
void print_error(char *msg);

#endif // SNAKE_CS_OPTIONS_H