#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "sn_options.h"

/*
 * snake_cs --gui=terminal --name=vladimir --host=127.0.0.1:123
 * snake_cs --connect-to=127.0.0.1:1234 --gui=terminal --name=larisa
 * snake_cs --help -h
 * snake_cs --version -v
 */

static struct option long_options[] = {
    {"version", no_argument, 0, 'v'},          // [0] SN_Options.show_version
    {"help", no_argument, 0, 'h'},             // [1] SN_Options.show_help
    {"gui", required_argument, 0, 'g'},        // [2] SN_Option.gui
    {"name", required_argument, 0, 'n'},       // [3] SN_Option.name
    {"connect-to", required_argument, 0, 'c'}, // [4] SN_Option.connect
};

static char short_options[] = "vhg:n:c:";

int sn_parse_long_option(SN_Options *opts, int index)
{
    switch (index)
    {
    case 0:
        opts->show_version = 1;
        break;
    case 1:
        opts->show_help = 1;
        break;
    case 2:
        if (strcmp(optarg, "terminal") == 0)
        {
            opts->gui = gui_terminal;
        }
        else if (strcmp(optarg, "opengl") == 0)
        {
            opts->gui = gui_opengl;
        }
        break;
    case 3:
        if (optarg)
        {
            sn_set_str_value(opts->name, optarg, 20);
        }
        break;
    case 4:
        if (optarg)
        {
            sn_set_str_value(opts->connect, optarg, 20);
        }
        break;
    default:
        break;
    }

    return 0;
};

int sn_parse_short_option(SN_Options *opts, int c)
{
    switch (c)
    {
    case 'v':
        opts->show_version = 1;
        break;
    case 'h':
        opts->show_help = 1;
        break;
    case 'g':
        if (strcmp(optarg, "terminal") == 0)
        {
            opts->gui = gui_terminal;
        }
        else if (strcmp(optarg, "opengl") == 0)
        {
            opts->gui = gui_opengl;
        }
        else
        {
            print_error("unknown gui type");
        }
        break;
    case 'n':
        if (optarg && strcmp(opts->name, "") == 0)
        {
            sn_set_str_value(opts->name, optarg, 20);
        }
        break;
    case 'c':
        if (optarg && strcmp(opts->connect, "") == 0)
        {
            sn_set_str_value(opts->connect, optarg, 20);
        }
        break;
    default:
        break;
    }

    return 0;
};

SN_Options sn_parse_options(int argc, char *argv[])
{
    SN_Options parsed_options = {
        .show_version = 0,
        .show_help = 0,
        .gui = gui_none,
        .name = "",
        .connect = "",
    };

    int c;

    while (1)
    {
        int option_index = -1;
        c = getopt_long(argc, argv, short_options, long_options, &option_index);

        if (c == -1)
            break;

        if (option_index >= 0)
        {
            sn_parse_long_option(&parsed_options, option_index);
        }

        sn_parse_short_option(&parsed_options, c);
    }

    if (strcmp(parsed_options.name, "") == 0)
    {
        sn_set_str_value(parsed_options.name, "guest", 20);
    }

    return parsed_options;
}

void print_error(char *msg)
{
    puts(msg);
}

void sn_set_str_value(char *dest, char *src, int len)
{
    memset(dest, '\0', len);

    int i;
    for (i = 0; i < len - 1; i++)
    {
        char c = src[i];

        if (c && c != '\0')
        {
            dest[i] = src[i];
        }
        else
        {
            break;
        }
    }
    dest[i] = '\0';
}