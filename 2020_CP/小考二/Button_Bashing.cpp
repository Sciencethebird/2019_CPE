// Button Bashing

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
#include <bitset>
typedef long long ll;
using namespace std;
const int inf = 1<<30;
int extra, minstep;

void solve(vector<int> &buttons, int goal){
    vector<int> vst(3601, inf);
    queue<int> q;
    q.push(0);
    vst[0] = 0;
    while(!q.empty()){
        
        int now = q.front();
        q.pop();
        int len = vst[now] +1;
        /*
        if(now>=goal && now - goal < extra){
            extra = now - goal;
            minstep = vst[now];
        }*/
        
        for(int i = 0; i<buttons.size(); i++){
            int next = now+buttons[i];
            next = min(3600, next);
            if(next>=0 && vst[next] == inf){
                q.push(next);
                vst[next] = len;
            }
        }
    }
    for(int i = goal; i<=3600; i++){
        if(vst[i] != inf){
            cout << vst[i] << " " << i - goal << endl;
            break;
        }
    }
 
}

int main(int argc, const char * argv[]) {
    int cases;
    cin >> cases;
 
    while(cases--){
        int nb, goal;
        cin >> nb >> goal;
        vector<int> buttons(nb);
        minstep = inf; extra = inf;
        
        for(auto &i:buttons){
            cin >> i;
        }
        solve(buttons, goal);
        //cout << minstep << " " << extra << endl;
    }
    
    return 0;
}


/*
 3 1
 1000 1001 -2000
 */
