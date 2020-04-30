// Falling Apples TLE
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

int main(int argc, const char * argv[]) {
    int m, n;
    cin >> m >> n;
    
    deque<char> space[n];
    
    for(int i = 0; i< m; ++i){
        for(int j = 0; j< n; ++j){
            char in;
            cin >> in;
            space[j].push_front(in);
        }
    }
  
   // int idx = 0;
    for(int c = 0; c< n; c++){
        for(int i = 1; i< m; ++i){
            if(space[c][i] == '.'){
                
            }else if(space[c][i] == '#'){
                
            }else if(space[c][i] == 'a'){
                int now = i-1;
                while(space[c][now] =='.'){
                    now--;
                }
                now++;
                if(now != i){
                    space[c][now] = 'a';
                    space[c][i] = '.';
                }
                
            }
        }
    }
    
    for(int i = m-1; i>= 0; --i){
        for(int j = 0; j< n; ++j){
            cout << space[j][i];
        }cout << endl;
    }
    return 0;
}
/*
a . # # .
. . # a a
# . # # a
. . # . a
a . # # #
*/

