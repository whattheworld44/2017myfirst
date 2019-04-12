#include <stdio.h>
#include <stdlib.h>
#define MINI ((double)(0.000001))

int main()
{
    int n; scanf("%d",&n);
    double e; scanf("%lf",&e);
    int p[n];
    double c[n];
    double t[n];

    double answer[n];
    for(int i=0; i<n; i++){
        scanf("%d%lf%lf",&p[i], &c[i], &t[i]);
    }

    for(int i=0; i<n; i++){
        
        double worst = 0;
        for(int j=i+1; j<n; j++){
            if(worst < c[j]){
                worst = c[j];
            }
        } 
        answer[i] = worst;
        int flag = 1;
        while(flag){
            
            double q=0;
            
            for(int j=0; j<i; j++){
                q += ((double)((int)((answer[i]+e-MINI)/t[j]) +1 ))*c[j];
            }
            q += worst;
            double k = q - answer[i];
            if(k < 0){
                k = -k;
            }
            if(k < MINI){
                flag = 0;
            }
            else if(answer[i] > q){
                answer[i] = -1;
                flag = 0;
            }
            else{
                answer[i] = q;
            }
        }
        if(answer[i] != -1){
            answer[i] += c[i];
        }
        printf("P%d: %lf\n",p[i],answer[i]);
    }
    return 0;
}
