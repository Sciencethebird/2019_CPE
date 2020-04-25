// Hydra's Heads
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
typedef long long ll;
using namespace std;

map<pair<int, int>,int> vst;

int inf = 1<<29;

int find(int h, int t){
    //cout << h << t << endl;
    if(vst.count({h, t})){
        return vst[{h, t}];
    }
    int best = inf;
    //if(t<=2 && h <=2){
        //best = min(best, find(h, t+1))
    //}
    if(h>=2){
        best = min(best, find(h-2, t));
    }
    if(t>=2){
        best = min(best, find(h+1, t-2));
    }
    if(h<=2 && t<=2){
        best = min(best, find(h, t+1));
    }
    best++;
    vst[{h, t}] = best;
    return best;
}

int main(int argc, const char * argv[]) {
    
    vst[{0, 0}] = 0;
    vst[{1, 0}] = inf;
    vst[{0, 1}] = 6;
    vst[{0, 2}] = 5;
    vst[{2, 1}] = 7;
    vst[{2, 0}] = 1;
    vst[{1, 2}] = 2;
    int H, T;
    //cout << (1<<30) << endl;
    while(cin >> H >> T){
        if(H==0 && T == 0) break;
        int best = find(H, T);
        if(best >= inf){
            cout << -1 << endl;
        }else{
            cout << best << endl;
        }
        
    }
    return 0;
}


