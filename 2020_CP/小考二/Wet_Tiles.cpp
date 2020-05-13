// Wet Tiles

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

vector<pair<int, int>> mv = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}
};

void solve(vector<vector<bool>>& mp, vector<pair<int, int>>& Leaks, int T){
    int ans = 0, iter = 0;
    unsigned long same_epc = Leaks.size();
    queue<pair<int, int>> q;
    for(auto i:Leaks){
        q.push(i);
        mp[i.first][i.second] = 1;
    }
    while(!q.empty()){
        
        same_epc--;
        pair<int, int> now = q.front();
        q.pop();
        
        for(auto i:mv){
            int nx = now.first+i.first;
            int ny = now.second+i.second;
            if(!mp[nx][ny]){
                q.push({nx, ny});
                mp[nx][ny] = 1;
                ans++;
            }
        }
        if(same_epc == 0){
            iter++;
            same_epc = q.size();
            if(iter == T-1){
                cout << ans+Leaks.size() << endl;
                return;
            }
        }
    }
    cout << ans+Leaks.size() << endl;
}
int main(int argc, const char * argv[]) {
    int X, Y, T, L, W;
    while(cin>> X){
        if(X == -1) break;
        cin >> Y >> T >> L >> W;
        vector<pair<int, int>> leaks(L);
        
        vector<bool> temp(Y+2, 0);
        vector<bool> ones(Y+2, 1);
        temp[0] = 1; temp[Y+1] = 1;
        vector<vector<bool> > mp;
        mp.push_back(ones);
        for(int i = 0; i<X;++i){
            mp.push_back(temp);
        }
        mp.push_back(ones);
    
        for(auto &i:leaks){
            cin >> i.first>> i.second;
        }
        for(int i = 0; i< W; ++i){
            int x0, x1, y0, y1;
            cin >> x0 >> y0 >> x1 >> y1;
            int dx = x1 - x0, dy = y1 - y0;
            int mx = 0, my = 0;
            if(dx>0) mx = 1;
            else if(dx<0)mx = -1;
            if(dy>0) my = 1;
            else if(dy<0) my = -1;
            int dd = max(abs(dx), abs(dy));
            for(int k = 0; k<= dd; k++){
                
                mp[x0][y0] = true;
                x0+=mx; y0+=my;
            }
        }
        /*
        for(int i = 0; i<= X+1; i++){
            for(int j = 0; j<=Y+1; j++){
                cout << mp[i][j]<<" ";
            }cout << endl;
        }*/
        solve(mp, leaks, T);
    }
    return 0;
}
