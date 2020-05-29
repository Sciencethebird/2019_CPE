// The Morning after Halloween_BFS
 
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

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <math.h>

typedef long long ll;
using namespace std;
const int inf = 1<<30;

int s[3], t[3];
int G[200][5];
int degree[200];
int dst[200][200][200];
int dx[5] = {0, 0, 0, -1, 1};
int dy[5] = {0, 1, -1, 0, 0};

bool conflict(int a, int a_nxt, int b, int b_nxt){
    return (a_nxt == b_nxt) || ( (a == b_nxt) && (a_nxt == b) );
}
int bfs(){
    queue<int> q1, q2, q3;
    q1.push(s[0]); q2.push(s[1]); q3.push(s[2]);
    dst[s[0]][s[1]][s[2]] = 0;
    while(!q1.empty()){
        int a_now = q1.front(), b_now = q2.front(), c_now = q3.front();
        q1.pop();q2.pop();q3.pop();
        if(a_now == t[0] && b_now == t[1] & c_now == t[2]){
            //cout << "found!" << endl;
            return dst[a_now][b_now][c_now];
        }
        for(int i = 0; i< degree[a_now]; i++){
            int a_nxt = G[a_now][i];
            for(int j = 0; j< degree[b_now]; j++){
                int b_nxt = G[b_now][j];
                if(conflict(a_now, a_nxt, b_now, b_nxt)) continue;
                for(int k = 0; k< degree[c_now]; k++){
                    int c_nxt = G[c_now][k];
                    if(conflict(b_now, b_nxt, c_now, c_nxt) || conflict(a_now, a_nxt, c_now, c_nxt))
                        continue;
                    if(dst[a_nxt][b_nxt][c_nxt] == -1){
                        dst[a_nxt][b_nxt][c_nxt] = dst[a_now][b_now][c_now]+1;
                        q1.push(a_nxt);
                        q2.push(b_nxt);
                        q3.push(c_nxt);
                    }
                
                }
            }
        }
    }
    return -1;
}
int main(int argc, const char * argv[]) {
    int w, h, n;
    while(cin >> w >> h >> n && w){
        char graph[20][20];
        getchar(); // ignore newline
        
        // read the map
        for(int i = 0; i < h; i++){
            fgets(graph[i], 20, stdin);
        }
        
        // number each non-'#' element for graph building later
        // find start, terminate point
        int cnt = 0, x[200], y[200], ID[20][20];
        for(int i = 0; i< h; i++) for(int j = 0; j< w; j++){
            if(graph[i][j] != '#'){
                x[cnt] = i; y[cnt] = j; ID[i][j] = cnt;
                if(islower(graph[i][j]))
                    s[graph[i][j] - 'a'] = cnt;
                else if(isupper(graph[i][j]))
                    t[graph[i][j] - 'A'] = cnt;
                cnt++;
            }
        }
        
       /*
        for(int i = 0; i< h; i++){
            for(int j = 0; j< w; j++){
                if(graph[i][j] != '#'){
                    cout << ID[i][j];
                }else cout << '#';
            }
            cout << endl;
        }*/
        
        // building connection table
        for(int i = 0; i< cnt; i++){
            degree[i] = 0;
            for(int j = 0; j< 5; j++){
                int nx = x[i]+dx[j], ny = y[i]+dy[j];
                if(graph[nx][ny]!='#') G[i][degree[i]++] = ID[nx][ny];
            }
        }
        /*
        for(int i = 0; i<= cnt; i++){
            for(int j = 0; j< degree[i]; j++){
                cout << G[i][j];
            }cout << endl;
        }*/
        
        // dummy ghost so you don't need to worry about different number of ghost
        if(n <= 2)  { degree[cnt] = 1; G[cnt][0] = cnt;    s[2] = t[2] = cnt++; }
        if(n <= 1)  { degree[cnt] = 1; G[cnt][0] = cnt;    s[1] = t[1] = cnt++; }
      
        memset(dst, -1, sizeof(dst));
        printf("%d\n", bfs());
        
    }
     
}

// learn from original code :
// https://blog.csdn.net/qq_29169749/article/details/51420097
/*
5 5 2
#####
#A#B#
#   #
#b#a#
#####
16 4 3
################
## ########## ##
#    ABCcba    #
################
 */
/*
 10 5 3
 ##########
 #B  # #  #
 #A#Ccba ##
 #   ### ##
 ##########
 10 5 3
 ##########
 #A  # #  #
 #B#Ccba ##
 #   ### ##
 ##########
 10 5 3
 ##########
 #A  # #  #
 #B#Ccba ##
 ### ### ##
 ##########
 10 5 3
 ##########
 # BA# #  #
 ###Ccba ##
 ### ### ##
 ##########
 10 5 3
 ##########
 # AB# #  #
 ###Ccba ##
 ### ### ##
 ##########
 10 5 3
 ##########
 # BA## # #
 ###Ccba  #
 ####### ##
 ##########
 10 5 3
 ##########
 # AB## # #
 ###Ccba  #
 ####### ##
 ##########
 10 5 3
 ##########
 # AB#### #
 # #Ccba  #
 #   ### ##
 ##########
 10 5 3
 ##########
 # A #### #
 # #Ccba  #
 # B ### ##
 ##########
 10 5 3
 ##########
 # A #### #
 ###Ccba  #
 # B ### ##
 ##########
 10 5 3
 ##########
 # A #### #
 # #Ccba  #
 # B#### ##
 ##########
 10 5 3
 ##########
 # B #### #
 # #Ccba  #
 # A#### ##
 ##########
 10 5 3
 ##########
 # B #### #
 #c#C ba  #
 # A#### ##
 ##########
 10 5 3
 ##########
 #aB #### #
 #b#C     #
 #cA#### ##
 ##########
 10 5 3
 ##########
 #aB     ##
 #c##### C#
 #bA     ##
 ##########
 10 5 3
 ##########
 #aB     ##
 #b##### C#
 #cA     ##
 ##########
 10 5 3
 ##########
 #aB#    ##
 #b##### C#
 #cA     ##
 ##########
 10 5 3
 ##########
 #cB#    ##
 #a##### C#
 #bA     ##
 ##########
 10 5 3
 ##########
 #aB#    ##
 #c##### C#
 #bA     ##
 ##########
 0 0 0

 */
