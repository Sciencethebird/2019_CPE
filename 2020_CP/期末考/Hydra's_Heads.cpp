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

bool found;
int inf = 1<<29;
pair<int, int> goal;
int find(int h, int t, int step){
    cout << h << t << step <<endl;
    if({h, t} == goal){
        found = 1;
        return <#expression#>
    }
    if(!found){
        step++;
        if(vst.count({h, t})){
            if(step<vst[{h, t}]) vst[{h, t}] = step;
        }else{
            vst[{h, t}] = step;
        }
        

        if(h>=2){
            find(h-2, t+3, step);
        }
        if(t>=2){
            find(h, t-2, step);
        }
        if(t>=1){
            find(h+2, t-1, step);
        }
        find(h+3, t, step);
    }else{
        return vst[goal];
    }
    return -1;
    
}

int main(int argc, const char * argv[]) {
    
    vst[{0, 0}] = 0;
    //vst[{1, 0}] = inf;
    //vst[{1, 1}] = 3;
    //vst[{0, 2}] = 5;
    //vst[{2, 1}] = 7;
    //vst[{2, 0}] = 1;
    //vst[{1, 2}] = 2;
    int H, T;
    //cout << (1<<30) << endl;
    while(cin >> H >> T){
        goal = {H, T};
        find(H, T, 0);
        
    }
    return 0;
}



