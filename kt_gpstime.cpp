#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>
#include <time.h>
#include <string>
#include <iostream>
#include <vector>
#include "ktl_gpstime.h"

void
usage()
{
    std::cout << "Usage: kt_gpstime [-n|-t unixtime|-h]" << std::endl
              << "    -n, --now           \t show current gpstime." << std::endl
              << "    -i, --injection     \t show next next framefile(16s) beginning gpstime" << std::endl
              << "    -t, --time=unixtime \t convert unixtime to gpstime" << std::endl
              << "    -h, --help          \t show this usage information" << std::endl
              << "\n\t ##===============##" << std::endl
              << "\t   Expired on 28 December 2018 due to leap second" << std::endl
              << "\t ##===============##\n" << std::endl;
}


int
main (int argc, char **argv)
{
    if (argc == 1) {
        std::string BUFF;
        std::cin >> BUFF;
        printf("%ld\n",unix2gps((time_t) std::stol(BUFF, NULL, 10)));
        return 0;
    }
    int c;
    while (1)
    {
        static struct option long_options[] =
        {
            /* These options set a flag. */
            // {"verbose", no_argument,       &verbose_flag, 1},
            /* These options don’t set a flag.
             We distinguish them by their indices. */
            {"now",        no_argument,   0, 'n'},
            {"injection",  no_argument,   0, 'i'},
            {"time", required_argument,   0, 't'},
            {"help",       no_argument,   0, 'h'},
            {0, 0, 0, 0}
        };
        /* getopt_long stores the option index here. */
        int option_index = 0;
        c = getopt_long (argc, argv, "nit:h",
                         long_options, &option_index);

        
        /* Detect the end of the options. */
        if (c == -1)
            break;
        
        switch (c)
        {       
            case 'n':
                printf("%ld\n", unix2gps(time(NULL)));
                break;

            case 'i':
                printf("%ld\n", nextInjTime(time(NULL)));
                break;

            case 't':
                printf("%ld\n", unix2gps((time_t)std::stol(optarg, NULL, 10)));
                break;
                
            case 'h':
                usage();
                break;
                
            case '?':
                /* getopt_long already printed an error message. */
                break;
                
            default:
                abort ();
        }
    }
     
    /* Print any remaining command line arguments (not options). */
    if (optind < argc)
    {
        printf ("non-option ARGV-elements: ");
        while (optind < argc)
            printf ("%s ", argv[optind++]);
        putchar ('\n');
    }
    
    exit (0);
}
