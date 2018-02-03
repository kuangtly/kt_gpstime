#include "stdio.h"
#include <iostream>
#include <vector>
#include "time.h"
#include "ktl_gpstime.h"

typedef struct LeapSec{
    time_t leapsec;
    time_t shift;
} LeapSec;

std::vector<LeapSec> leapseclist = {
    {2571782400, 20},    // 1 Jul 1981
    {2603318400, 21},    // 1 Jul 1982
    {2634854400, 22},    // 1 Jul 1983
    {2698012800, 23},    // 1 Jul 1985
    {2776982400, 24},    // 1 Jan 1988
    {2840140800, 25},    // 1 Jan 1990
    {2871676800, 26},    // 1 Jan 1991
    {2918937600, 27},    // 1 Jul 1992
    {2950473600, 28},    // 1 Jul 1993
    {2982009600, 29},    // 1 Jul 1994
    {3029443200, 30},    // 1 Jan 1996
    {3076704000, 31},    // 1 Jul 1997
    {3124137600, 32},    // 1 Jan 1999
    {3345062400, 33},    // 1 Jan 2006
    {3439756800, 34},    // 1 Jan 2009
    {3550089600, 35},    // 1 Jul 2012
    {3644697600, 36},    // 1 Jul 2015
    {3692217600, 37}    // 1 Jan 2017
};

time_t
unix2gps(time_t unixTime)
{
    return unixTime-315964800+leapShift(unixTime);
}

time_t
leapShift(time_t unixTime)
{
    if (unixTime < 315964800){     // gpstime < 0
    //if (0){     // bypass assert(gpstime>=0)
        myexit("illegal gpstime");
    } else {
        time_t t0 = unixTime+2208988800; // seconds since 1900/01/01
        time_t shift = 0;
        std::vector<LeapSec>::iterator it;
        for (it=leapseclist.begin(); it!=leapseclist.end(); ++it) {
            if (t0 > it->leapsec){
                shift = it->shift-19; // when gpstime=0, there are 19s leap
            }
        } 
        return shift;
    }
}

