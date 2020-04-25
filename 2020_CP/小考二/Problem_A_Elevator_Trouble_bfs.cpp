// Problem A Elevator Trouble bfs
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
typedef long long ll;
using namespace std;

map<int, int> vst;
int f, s, g, u, d;

void find(int now, int cnt){
    
    if(vst.count(now)){
        return;
    }
    vst[now] = cnt;
    
    if(now+u<=f){
        cnt++;
        find(now+u, cnt);
    }
    if(now-d>=1){
        cnt++;
        find(now-d, cnt);
    }
}
ll inf = (ll)1<<62;
int main(int argc, const char * argv[]) {
    
    cin >> f >> s >> g >> u >> d;
    
    vector<ll> vst(f+1, inf);
    queue<int> q;
    q.push(s);
    vst[s] = 0;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        if(now == g){
            cout << vst[now] << endl;
            return 0;
        }
    
        if(now+u<=f && vst[now+u]==inf){
            q.push(now+u);
            vst[now+u] = vst[now]+1;
        }
        if(now-d>=1 && vst[now-d]==inf){
            q.push(now-d);
            vst[now-d] = vst[now]+1;
        }
    }

    cout << "use the stairs" << endl;
    return 0;
}


