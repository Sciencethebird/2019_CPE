//  10009:All Roads Lead Where? BFS

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <map>
#include <queue>
using namespace std;

map<string, int> get_idx;
vector<string> graph[30];

void BFS(string s, string t){
    // standard bfs
    int start = get_idx[s], end = get_idx[t];
    int distance[30];
    for(int i = 0; i< 30; i++) distance[i] = 0;
    queue<int> Q;
    Q.push(start);
    distance[start] = 1;
    while(!Q.empty()){
        int curr = Q.front();
        Q.pop();
        for(auto neb : graph[curr]){
            if(!distance[get_idx[neb]]){
                Q.push(get_idx[neb]);
                distance[get_idx[neb]] = distance[curr] +1;
            }
        }
    }
    
    // trace back
    int d = distance[end];
    string out = "";
    // out += t[0];
    while(d > 1){
        for(auto neb : graph[end]){
            if(distance[get_idx[neb]] == d - 1){
                end = get_idx[neb];
                --d;
                out  = neb[0] + out;
                break;
            }
        }
    }
    cout << out+t[0] << endl;
}


int main(int argc, const char * argv[]) {
    int cases;
    string a, b;
    cin >> cases;
    while(cases--){
        
        for(int i = 0; i< 30; i++) graph[i].clear();
        get_idx.clear();
        
        int num_of_edges, num_of_query, idx = 1;
        cin >> num_of_edges >> num_of_query;
        while(num_of_edges--){
            cin >> a >> b;
            if(!get_idx[a]) get_idx[a] = idx++;
            if(!get_idx[b]) get_idx[b] = idx++;
            graph[get_idx[a]].push_back(b);
            graph[get_idx[b]].push_back(a);
        }
        while(num_of_query--){
            string a, b;
            cin >> a >> b;
            BFS(a,b);
        }
        if(cases) cout << endl;
    }
    return 0;
}
 

/*
2

7 3
Rome Turin
Turin Venice
Turin Genoa
Rome Pisa
Pisa Florence
Venice Athens
Turin Milan
Turin Pisa
Milan Florence
Athens Genoa

7 3
Rome Turin
Turin Venice
Turin Genoa
Rome Pisa
Pisa Florence
Venice Athens
Turin Milan
Turin Pisa
Milan Florence
Athens Genoa
 */

