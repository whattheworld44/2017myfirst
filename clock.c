#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/syscall.h>
#include <time.h>

#define GET_TIME 314
#define MY_TIME 265

int main(){
    struct timespec tt,vv;
    clock_gettime(CLOCK_REALTIME, &tt);
    //syscall(MY_TIME,&tt);
    printf("0: %lu.%09lu\n",tt.tv_sec, tt.tv_nsec);
    unsigned long start_sec, start_nsec, end_sec, end_nsec;
    syscall(GET_TIME, &start_sec, &start_nsec);
    printf("1: %lu.%09lu\n",start_sec, start_nsec);
    for(int i=0; i<300000000; i++);
    syscall(GET_TIME, &end_sec, &end_nsec);
    printf("2: %lu.%09lu\n",end_sec, end_nsec);
    //syscall(MY_TIME,&vv);
    clock_gettime(CLOCK_REALTIME, &vv);
    printf("3: %lu.%09lu\n",vv.tv_sec,vv.tv_nsec);
    return 0;
}
