// Falling Apples
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
    
    // sentinal
    for(int j = 0; j< n; ++j){
        space[j].push_back('#');
    }
       
    deque<char> out[n];
    for(int c = 0; c< n; c++){
        int acnt = 0, dcnt = 0;
        for(int i = 0; i<= m; ++i){
            if(space[c][i] == '#'){
                for(int j = 0; j< acnt; j++)
                    out[c].push_back('a');
                for(int j = 0; j< dcnt; j++)
                    out[c].push_back('.');
                out[c].push_back('#');
                acnt = 0; dcnt = 0;
            }else if(space[c][i]=='.'){
                dcnt++;
            }else if(space[c][i]=='a'){
                acnt++;
            }
        }
    }
    
    for(int i = m-1; i>= 0; --i){
        for(int j = 0; j< n; ++j){
            cout << out[j][i];
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
 
aaa.a
aa.a.
a.a..
...a.
aaa.a
aa.a.
a.a..
...a.
*/
