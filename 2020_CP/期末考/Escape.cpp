// Escape
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <math.h>
#include <deque>
#include <sstream>
#include <queue>
#include <unordered_map>
typedef long long ll;
using namespace std;

int main(int argc, const char * argv[]) {
    
    ll x, bd = 1000000007;
    scanf("%lld", &x);
    ll t1 = 1, t2 = 4;
    if(x == 1) {
        printf("%lld\n", t1);
        return 0;
    }
    if(x == 2){
        printf("%lld\n", t2);
        return 0;
    }
        
    for(int i = 2; i< x; i++){
        ll temp = t2;
        //t2 = t1;
        t2 = ((4*t1)+(2*t2))%bd;
        t1 = temp;
    }
    printf("%lld\n", t2);
    return 0;
}




