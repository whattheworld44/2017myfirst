#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/syscall.h>

#define GET_TIME 314

int main(){
    unsigned long start_sec, start_nsec, end_sec, end_nsec;
    syscall(GET_TIME, &start_sec, &start_nsec);
    printf("1: %lu.%09lu\n",start_sec, start_nsec);
    for(int i=0; i<1000000000; i++);
    syscall(GET_TIME, &end_sec, &end_nsec);
    printf("2: %lu.%09lu\n",end_sec, end_nsec);
    return 0;
}
