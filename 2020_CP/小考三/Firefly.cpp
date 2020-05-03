// Firefly

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
#include <iomanip>
typedef long long ll;
using namespace std;

int comp(int a, int b){
    return a >b;
}
int main(int argc, const char * argv[]) {
    ll N, H;
    cin >> N >> H;
    vector<int> ub, lb;
    vector<ll> cnt(1+H, 0);
    for(int i = 0; i< N; i++){
        int temp;
        scanf("%d", &temp);
        if(i % 2==0){
            lb.push_back(temp);
        }else{
            ub.push_back(H-temp);
        }
    }
    sort(lb.begin(), lb.end());
    sort(ub.begin(), ub.end(), comp);
    int last = 1, hit = lb.size();
    for(int i = 0; i< lb.size(); i++){
        for(int j = last; j<= lb[i]; j++){
            cnt[j] = hit;
        }
        last = lb[i]+1;
        hit--;
    }
   
    last = H, hit = ub.size();
    for(int i = 0; i< ub.size(); i++){
        for(int j = last; j> ub[i]; j--){
            cnt[j] += hit;
        }
        last = ub[i];
        hit--;
    }
    int min = cnt[1], nnn = 0;
    for(int i = 1; i< cnt.size(); i++){
        if(cnt[i]< min){
            nnn = 0;
            min = cnt[i];
        }
        if(cnt[i] == min){
            nnn++;
        }
    }
    /*
    for(auto i: cnt){
        cout << i << " ";
    }cout << endl;
     */
    cout << min << " " << nnn << endl;
    return 0;
}


/*
14 5
1
1
1
1
1
1
1
1
1
1
1
1
1
1
*/
