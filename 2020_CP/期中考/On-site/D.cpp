// D

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

int xs, ys, xt, yt;
vector<pair<int, int>> mv = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}
};


void solve(vector<vector<int>>&mp,vector<vector<bool>>&vst, pair<int, int>now, vector<int> max, int diff){
    max.push_back(diff);
    vst[now.first][now.second] = 1;
    if(now.first == xt && now.second == yt){
        cout << "ads" << endl;
        for(auto i: max){
            cout << i << " ";
        }cout << endl;
        return;
    }
    cout << now.first << " " << now.second << endl;
    for(auto i: mv){
        int nx = now.first+i.first, ny = now.second+i.second;
        if(mp[nx][ny] == inf || vst[nx][ny]){
            continue;
        }
        int diff = mp[nx][ny] - mp[now.first][now.second];
        diff = abs(diff);
        
        //if(diff> max.back()){
            
        //}
        solve(mp, vst, {nx, ny}, max, diff);
    }
    vst[now.first][now.second] = 0;
}

int main(int argc, const char * argv[]) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> temp(m+2, inf);
    vector<vector<int>> mp(n+2, temp);
    vector<bool> zeros(m+2, 0);
    vector<vector<bool>> vst(n+2, zeros);
    for(int i = 1; i<= n; i++){
        for(int j = 1; j<= m; j++){
            int temp;
            cin >> temp;
            mp[i][j] = temp;
        }
    }
    for(int i = 0; i< n+2; i++){
        for(int j = 0; j< m+2; j++){
            cout << mp[i][j] << " ";
        }cout << endl;
    }
    cin >> xs >> ys >> xt >> yt;
    solve(mp,vst, {xs, ys}, {0});
    return 0;
}
