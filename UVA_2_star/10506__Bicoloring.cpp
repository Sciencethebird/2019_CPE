//  10506: Bicoloring

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <stdlib.h>
#include <deque>
#include <math.h>
#include <algorithm>
#include <fstream>
using namespace std;

int v_num, e_num;
bool flag;

void bfs(vector< vector<bool> > &g){
    deque<int> q;
    vector<bool> color(v_num, false), visited(v_num, false);
    q.push_back(0);
    while(!q.empty()){
        int idx = q.front();
       
        q.pop_front();
        for(int i = 0; i <v_num; i++ ){
            if(g[idx][i] ){
                if(!visited[i]){
                    visited[i] = true; // wa if put outside
                    q.push_back(i);
                    color[i] = !color[idx];
                }else{
                    if(color[i] == color[idx]){
                        flag = 1;
                        return;
                    }
                }
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    
    while(cin >> v_num){
        if(!v_num) break;
        
        cin >> e_num;
        
        vector<bool> temp(v_num, 0);
        vector< vector<bool> > edges(v_num, temp);
        int a, b;
        
        for(int i = 0; i< e_num; i++){
            cin >> a >> b;
            edges[a][b] = 1;
            edges[b][a] = 1;
        }
        bfs(edges);
        if(flag)
            cout << "NOT BICOLORABLE." << endl;
        else
            cout << "BICOLORABLE." << endl;
            
        flag = 0;
    }
  
   
    return 0;
}
 






