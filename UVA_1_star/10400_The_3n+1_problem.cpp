//  10400:The 3n + 1 problem

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;

static unsigned long long ans = 0;
void rec(unsigned long long n){
    ans++;
    //cout << n << endl;
    if(n == 1) return;
    if(n%2 == 1) rec(3*n+1);
    else rec(n/2);
}


int main(int argc, const char * argv[]) {
    
    int lb, ub;
    while(cin >> lb >> ub){
        int t1, t2;
        if(lb > ub) {
            t1 = ub;
            t2 = lb;
        }else{
            t1 = lb;
            t2 = ub;
        }
        unsigned long long max = 0;
        for(int i = t1; i <= t2; i++){
            ans = 0;
            rec(i);
            if(ans > max) max = ans;
        }
        cout << lb <<" "<< ub << " "<<max << endl;
    }
    return 0;
}
