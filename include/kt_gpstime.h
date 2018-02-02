#ifndef _KT_GPSTIME_H
#define _KT_GPSTIME_H

time_t unix2gps(time_t);
time_t leapShift(time_t);
void myexit(const char*);

#endif // _KT_GPSTIME_H

