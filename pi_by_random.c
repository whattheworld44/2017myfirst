#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TEST 3000000               // number of test

int main()
{
    srand(time(NULL));
    double circle = 0;             // 1/4circle
    double total = TEST;           // total test
    int time = TEST;
    while(time--){
        double x = (double)rand()/(double)RAND_MAX;
        double y = (double)rand()/(double)RAND_MAX;
        if((x*x + y*y) < 1.000007){
            circle++;
        }
    }
    double pi = 4*(circle/total);  // count pi
    printf("pi is %lf\n",pi);
    return 0;
}