#include "stdlib.h"
#include "stdio.h"
#include "time.h"
#include "kt_gpstime.h"

void
myexit(char* ErrMsg)
{
    printf("ERROR: %s \n", ErrMsg);
    exit(-1);
}


int main(int argc, char** argv)
{
    if (argc == 1) {
        printf("%ld\n",unix2gps(time(NULL)));
        return 0;
    } else if (argc == 2){
        printf("%ld\n",unix2gps((time_t) strtol(argv[1], NULL, 10)));
        return 0;
    } 
    return 0;
}


