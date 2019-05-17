#include <cstdio>
#include <iostream>
#include <random>
#include <algorithm>
#include <ctime>
#include <string>
#define MAXN 1000


using namespace std;

void init(string &cmp, int n){
    for(int i=0; i<n; i++){
        cmp.push_back((rand()%2) + '0');
    }
}

void strategy(string &B, int n, string&A){
    //strategy 1
    /*do{
        string buf;
        init(buf,n);
        B = buf;
    }
    while(A.compare(B) == 0);*/

    //strategy 2
    if(A[0] == '1'){
        B.push_back('0');
    }
    else{
        B.push_back('1');
    }
    B.append(A.substr(0, n-1));
}



int main()
{
    string A;
    string B;
    srand(time(NULL));

    int n; scanf("%d",&n);

    init(A, n);
    strategy(B, n, A);

    int counter_A_win = 0;
    int counter_B_win = 0;
    
    for(int i=0; i<MAXN; i++){
        int flag = 1;
        string cmp;
        init(cmp, n);

        while(flag){
            if(cmp.compare(A) == 0){
                flag = 0;
                counter_A_win++;
            }
            else if(cmp.compare(B) == 0){
                flag = 0;
                counter_B_win++;
            }
            else{
                cmp = cmp.substr(1);
                cmp.push_back((rand()%2) + '0');
                //cout << "cmp is " << cmp << "\n";
            }
        }
    }

    cout << "P(A) " << A << " = " << ((double)counter_A_win/(double)MAXN) << "\n";
    cout << "P(B) " << B << " = " << ((double)counter_B_win/(double)MAXN) << "\n";
    return 0;
}