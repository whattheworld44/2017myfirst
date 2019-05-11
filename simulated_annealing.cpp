#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <random>

#define MINI ((double)(0.000001))
#define MAXN (100000)
#define temperature (10000000)
#define RATE ((double)(0.999))

using namespace std;

typedef struct package{
    double c; 
    double t;
}Package;

double cost_f(int p[], Package pack[], double e, int n)
{
    double answer[n];
    double sum = 0;

    for(int i=0; i<n; i++){
        
        double worst = 0;
        for(int j=i+1; j<n; j++){
            if(worst < pack[j].c){
                worst = pack[j].c;
            }
        } 
        
        answer[i] = worst;
        int flag = 1;
        while(flag){
            
            double q=0;
            
            for(int j=0; j<i; j++){
                q += ((double)((int)((answer[i]+e-MINI)/pack[j].t) +1 ))*pack[j].c;
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
            answer[i] += pack[i].c;
        }
        printf("P%d: %lf\n",p[i],answer[i]);
        sum += answer[i];
    }
    return sum;
}


int main()
{
    int n; scanf("%d",&n);
    double e; scanf("%lf",&e);
    int p[n];
    Package pack[n];
    for(int i=0; i<n; i++){
        scanf("%d%lf%lf",&p[i], &pack[i].c, &pack[i].t);
    }
    
    double sum_worst;
    sum_worst = cost_f(p, pack, e, n);
    printf("---sum_worst = %lf ------\n",sum_worst);

    int min_cost = sum_worst;
    Package rem[n];
    for(int i=0; i<n; i++){
        rem[i].c = pack[i].c;
        rem[i].t = pack[i].t;
    }

    srand ( unsigned ( time(0) ) );
    double tem = temperature;
    while(tem > MINI){
        random_shuffle ( pack, pack + n );
        sum_worst = cost_f(p, pack, e, n);
        double delta_c = sum_worst - min_cost ;
        if(delta_c <= MINI){
            min_cost = sum_worst;
            for(int i=0; i<n; i++){
                rem[i].c = pack[i].c;
                rem[i].t = pack[i].t;
            }
        }
        else{
            double prob = exp(-(delta_c/tem));
            if((((double)rand())/(double)RAND_MAX) < prob){
                min_cost = sum_worst;
                for(int i=0; i<n; i++){
                    rem[i].c = pack[i].c;
                    rem[i].t = pack[i].t;
                }
            }
        }
        tem = tem*RATE;
        printf("---sum_worst = %lf ------\n",sum_worst);
    }
    sum_worst = cost_f(p, rem, e, n); 
    printf("---final sum_worst = %lf ------\n",sum_worst);
    printf("------------ answer -----------\n");
    for(int i=0; i<n; i++){
        printf("P%d: %lf %lf\n",p[i], rem[i].c, rem[i].t);
    }
    
    return 0;
}