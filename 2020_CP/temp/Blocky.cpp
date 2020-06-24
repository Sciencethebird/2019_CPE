// Blocky
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



bool found;
int inf = 1<<29;
pair<int, int> moves[4] = {{3, 0}, {-2, 3}, {2, -1}, {0, -2}};
map<pair<int, int>,ll> dis;

void build(){
    queue<pair<int, int>> q;
    q.push({0, 0});
    dis[{0, 0}] = 0;
    while(!q.empty()){
        pair<int, int> now = q.front();
        q.pop();
        ll dis_now = dis[now];
        if(now.first>100 || now.second>100){
            continue;
        }
        if(!dis.count({now.first+3, now.second}) ){
            dis[{now.first+3, now.second}] = dis_now+1;
            q.push({now.first+3, now.second});
        }
        if(now.first>=2){
            if(!dis.count({now.first-2, now.second+3}) ){
                dis[{now.first-2, now.second+3}] = dis_now+1;
                q.push({now.first-2, now.second+3});
            }
            
        }
        if(now.second>=1){
            if(!dis.count({now.first+2, now.second-1}) ){
                dis[{now.first+2, now.second-1}] = dis_now+1;
                q.push({now.first+2, now.second-1});
            }
        }
        if(now.second>=2){
            if(!dis.count({now.first, now.second-2}) ){
                dis[{now.first, now.second-2}] = dis_now+1;
                q.push({now.first, now.second-2});
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    
    build();
    int H, T;
    scanf("%d%d", &H, &T);
    cout << dis[{H, T}] << endl;
    return 0;
}



