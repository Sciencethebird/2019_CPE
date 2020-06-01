// Aries
 
#include <iostream>

#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <deque>
#include <sstream>
#include <queue>
#include <iomanip>
#include <bitset>
#include <unordered_map>

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <math.h>

typedef long long ll;
using namespace std;
const int inf = 1<<30;

int px[9] = {0, 0, 0, 1, 1, 1, 2, 2, 2};
int py[9] = {0, 1, 2, 0, 1, 2, 0, 1, 2};
vector<vector<int>> goal = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
vector<vector<int>> G;

map<vector<vector<int>>, int> vst;
map<vector<vector<int>>, int> color;


vector<vector<int>> CW(vector<vector<int>> g, int px, int py){
    int temp = g[px][py];
    g[px][py] = g[px+1][py];
    g[px+1][py] = g[px+1][py+1];
    g[px+1][py+1] = g[px][py+1];
    g[px][py+1] = temp;
    return g;
}
vector<vector<int>> CCW(vector<vector<int>> g, int px, int py){
    int temp = g[px][py];
    g[px][py] = g[px][py+1];
    g[px][py+1] = g[px+1][py+1];
    g[px+1][py+1] = g[px+1][py];
    g[px+1][py] = temp;
    return g;
}

int bfs(){
    queue<vector<vector<int> > > q;
    queue<vector<vector<int> > > qt;
    int iter = 0;
    q.push(G); qt.push(goal);
    vst[G] = 0; vst[goal] = 1;
    color[G] = 1; color[goal] = 2;
    int sdis = 0, tdis = 0;
    while(!q.empty() || !qt.empty()){
        ll q_len = q.size(), qt_len = qt.size();
        if(sdis+tdis>=10){
            return -1;
        }
        while(q_len--){
            vector<vector<int>> now = q.front();
            q.pop();
            sdis =vst[now];
            if(sdis>5){
                return -1;
            }
            for(int i = 0; i< 9; i++){
                vector<vector<int>> next_g = CW(now, px[i], py[i]);
                if(!color.count(next_g)){
                    vst[next_g] = sdis+1;
                    color[next_g] = 1;
                    q.push(next_g);
                }else if(color[next_g] == 2){
                    if(vst[now] +vst[next_g]>10) return -1;
                    return vst[now] +vst[next_g];
                }
            }
        }
        if(sdis+tdis>=10){
            return -1;
        }
        while(qt_len--){
            vector<vector<int>> now = qt.front();
            qt.pop();
            tdis =vst[now];
            if(tdis>5){
                return -1;
            }
            for(int i = 0; i< 9; i++){
                vector<vector<int>> next_g = CCW(now, px[i], py[i]);
                if(!color.count(next_g)){
                    vst[next_g] = tdis+1;
                    
                    color[next_g] = 2;
                    qt.push(next_g);
                }else if(color[next_g] == 1){
                    if(vst[now] +vst[next_g]>10) return -1;
                    return vst[now]+vst[next_g] ;
                }
            }
        }
        if(sdis+tdis>=10){
            return -1;
        }
    }
    
    return 1;
}
int main(int argc, const char * argv[]) {
    int cases;
    cin >> cases;
    while(cases--){
        vector<int> temp(4, 0);
        vector<vector<int> > g(4, temp);
        G = g;
        for(int i = 0; i< 4; i++){
            for(int j = 0; j< 4; j++){
                scanf("%d", &G[i][j]);
            }
        }
 
        vst.clear(); color.clear();
        int ans = bfs();
        if(ans>0)
            printf("%d\n", ans);
        else
            printf("HARD ARIES\n");
    }
    
    return 0;
}

/*
 4
 1 3 7 4
 5 2 6 8
 9 10 11 12
 13 14 15 16
 1 3 7 4
 5 2 6 8
 10 14 11 12
 9 13 15 16
 1 3 4 8
 5 2 14 15
 11 6 10 12
 9 7 13 16
 1 4 12 16
 8 9 2 3
 6 5 11 10
 13 14 7 15
 */
/*
1+3+6+10+15
2 3 4
*/

