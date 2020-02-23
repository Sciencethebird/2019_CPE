//  10009:All Roads Lead Where?

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
using namespace std;

struct node{
    node(){
        parent = -1;
    }
    void clear(){
        parent = -1;
        childs.clear();
    }
    int parent; // ancestor
    vector<int> childs;
};

bool connection[26][26];
node tree[26];

void dfs(int cur){
    for(int i = 0; i< 26; i++){
        if(connection[cur][i] == 1 && i != cur && i != tree[cur].parent){
            tree[cur].childs.push_back(i);
            tree[i].parent = cur;
            dfs(i);
        }
    }
}
string path_to_Rome(int cur){
    string path = "";
    while(1){
        path += (cur+'A');
        cur = tree[cur].parent;
        if(cur == -1) break;
    }
    return path;
}

int main(int argc, const char * argv[]) {
    int cases;
    cin >> cases;
    for(int k = 0; k< cases; k++){
        
        for(int i = 0; i<26; i++)
            for(int j = 0; j<26; j++)
                connection[i][j] = false;
        for(int i = 0; i<26; i++)
            tree[i].clear();
        int m, n;
        cin.ignore();
        cin >> m >> n;
        for(int i = 0; i< m; i++){
            char c1, c2;
            cin >> c1;
            cin.ignore(256, ' ');
            cin >> c2;
            cin.ignore(256, '\n');
            connection[c1-'A'][c2-'A'] = true;
            connection[c2-'A'][c1-'A'] = true;
        }
        
        // 建圖
        dfs('R' - 'A');
        if(k) cout << endl;
        for(int i = 0; i< n; i++){
            char c1, c2;
            string t1, t2;
            
            cin >> c1;
            cin.ignore(256, ' ');
            cin >> c2;
            cin.ignore(256, '\n');
            
            t1 = path_to_Rome(c1 - 'A');
            t2 = path_to_Rome(c2 - 'A');
            long long i1 = t1.size() -1, i2 = t2.size() -1;
            
            while(i1>=0 && i2>=0){
                if(t1[i1] == t2[i2]){
                    c1 = t1[i1];
                    i1--;
                    i2--;
                }else break;
        
            }
            // 剪掉重複路徑
            t2 = t2.substr(0, i2+1);
            t2 = string(t2.rbegin(), t2.rend());
            cout << t1.substr(0, i1+1) <<c1<<t2 << endl;
        }
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
Athens G

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
Athens G
 */

