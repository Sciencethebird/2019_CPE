// Grid

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
void solve(vector<vector<int> > &mp, int m, int n){
    vector<int> temp(n, -1);
    vector<vector<int> > dist(m, temp);
    queue<pair<int, int>> q;
    q.push({0,0});
    dist[0][0] = 0;
    while(!q.empty()){
        pair<int, int> now = q.front();
        q.pop();
        for(auto i: mv){
            int k = mp[now.first][now.second];
            int nm = now.first+k*i.first, nn = now.second+k*i.second;
            if(nm<m &&nm>=0 && nn<n && nn>=0 && dist[nm][nn]== -1){
                    dist[nm][nn] = dist[now.first][now.second]+1;
                    q.push({nm, nn});
            }
        }
    }
    cout << dist[m-1][n-1] << endl;
    /*
    for(auto i:dist){
        for(auto j:i){
            cout << j << " ";
        }cout << endl;
    }*/
}

int main(int argc, const char * argv[]) {
    int m, n;
    cin >> m >> n;
    vector<int> temp(n);
    vector<vector<int>> mp(m, temp);
    cin.ignore();
    for(int i = 0; i< m; ++i){
        string buffer;
        getline(cin, buffer);
        for(int j = 0; j< n; j++){
            mp[i][j] = buffer[j] - '0';
        }
    }
    solve(mp, m, n);
    return 0;
}
