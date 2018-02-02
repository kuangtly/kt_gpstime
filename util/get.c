#include <stdio.h>
int main(int argc, char** argv){
    FILE* f=popen("curl -O https://www.ietf.org/timezones/data/leap-seconds.list", "r");
    pclose(f);
    printf("Update Leap Second\n");
    return 0;
}
