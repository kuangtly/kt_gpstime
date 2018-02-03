#include "stdlib.h"
#include "stdio.h"
#include "time.h"
#include "ktl_gpstime.h"
#include <string>
#include <cstring>
#include <iostream>
#include <vector>

void
usage()
{
    std::cout << "Usage: kt_gpstime [-now | -]" << std::endl;
}

void
myexit(const char* ErrMsg)
{
    printf("ERROR: %s \n", ErrMsg);
    exit(-1);
}


int main(int argc, char** argv)
{
    if (argc == 1) {
        std::string BUFF;
        std::cin >> BUFF;
        printf("%ld\n",unix2gps((time_t) std::stol(BUFF, NULL, 10)));
        return 0;
    } else if (argc == 2) {
        if ( strncmp(argv[1], "-n", 2) || strncmp(argv[1], "--now", 2) ) {
            printf("%ld\n",unix2gps(time(NULL)));
        } else if ( strncmp(argv[1], "-h",2) || strncmp(argv[1], "--help", 2) ) {
            usage(); 
            return 0; 
        } else {
            printf("%ld\n",unix2gps((time_t) std::stol(argv[1], NULL, 10)));
        }
        return 0;
    } 
    return 0;
}


