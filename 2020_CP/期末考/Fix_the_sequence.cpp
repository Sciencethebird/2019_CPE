// Fix the sequence
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


bool valid(vector<ll>&a, vector<ll>&b, ll m, ll cap){
    ll n = a.size();
    ll forwardRun = n-1;
    ll backwardRun = 0;
    //cout << "CAP: " << cap << endl;
    ll lowest = max(a[0]%b[0], a[0]-b[0]*cap);
    //cout << "forward " << lowest ;
    for(ll i = 1; i< n; i++){
        ll t1 = lowest+1, t2 = (a[i]%b[i]) - t1%b[i];
        if(t2<0) t2 = t2+b[i];
        t1 = t1 + t2;
        lowest = max(a[i] - b[i]*cap, t1);
        //cout <<" "<< lowest;
        if(lowest > m || lowest > a[i] + cap * b[i]){
            forwardRun = i-1;
            break;
        }
    }//cout << endl;
    lowest = max(a[n-1] % b[n-1], a[n-1] - b[n-1] * cap);
    //cout << "backward " << lowest ;
    for(ll i = n-2; i>=0; i--){
        ll t1 = lowest+1, t2 = (a[i]%b[i]) - t1%b[i];
        if(t2<0) t2 = t2+b[i];
        t1 = t1 + t2;
        //cout <<" "<< lowest;
        lowest = max(a[i] - b[i]*cap, t1);
        if(lowest > m ||  lowest > a[i] + cap * b[i]){
            backwardRun = i+1;
            break;
        }
    }//cout << endl;
    //cout <<(forwardRun >0 && forwardRun >= backwardRun && backwardRun<n-1)<< endl;
    return forwardRun >0 && forwardRun >= backwardRun && backwardRun<n-1;
}
ll solve(vector<ll>&a, vector<ll>&b, ll m){
    if(!valid(a, b, m, 1<<30)) return -1;
    if(valid(a, b, m, 0)) return 0;
    ll step = 1 <<29;
    ll ans = 0;
    while(step > 0){
        //cout << ans << endl;
        if(!valid(a, b, m, ans+step))
            ans += step;
        step /=2;
        //cout << endl;
    }
    return ans+1;
}


int main(int argc, const char * argv[]) {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<ll> a(n), b(n);
    for(auto &i:a) scanf("%lld", &i);
    for(auto &i:b) scanf("%lld", &i);
    // cout << valid(a, b, m, 85)<< endl;;
    
    printf("%lld\n", solve(a, b, m));
    return 0;
}


/*
 10 10
 1 2 1 2 4 2 4 5 3 6
 1 2 3 4 5 4 3 2 1 1
 
 15 10
 1 2 1 2 4 2 4 5 3 6 5 3 6 7 5
 1 2 3 4 5 6 7 8 9 8 7 6 5 4 3
 
 15 10
 1 2 1 2 4 2 4 5 3 6 5 3 6 7 5
 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
 
 
 15 10
 1 2 1 2 4 2 4 1 1 1 34 75 5 64 86 2 10 3 6 5
 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
 
 20 10
 1 2 1 2 4 2 4 1 1 1 34 75 5 64 86 2 10 3 6 5
 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
 
 3 222
 2 22 222
 200 201 200
 
 3 222
 2 22 222
 200 201 200
 
 5 10
 1 2 3 4 5
9 9 9 9 9
 */

