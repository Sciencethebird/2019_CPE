// Sideways Sorting
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

bool comp(string c1, string c2){
    for(int i = 0; i< c1.size(); i++){
        if(c2[i] == c1[i])continue;
        if(c1[i]>='a' && c2[i]>='a'){
            return c1[i]<c2[i];
        }else if(c1[i]>='a' && c2[i]<'a'){
            if(c1[i]-'a' == c2[i]-'A')
                return c1[i]<c2[i];
            return c1[i]-'a'< c2[i]-'A';
        }else if(c1[i]<'a' && c2[i]>='a'){
            if(c1[i]-'A' == c2[i]-'a')
                return c1[i]<c2[i];
            return c1[i]-'A'< c2[i]-'a';
        }else if(c1[i]<'a' && c2[i]<'a'){
            return c1[i]<c2[i];
        }
    }
    return true;
}
bool comp2(string c1, string c2){
    for(auto&c :c1){
        c = tolower(c);
    }
    for(auto&c :c2){
        c = tolower(c);
    }
    return c1 < c2;
}

int main(int argc, const char * argv[]) {
    int m, n;
    bool first = true;
    while(cin >> m >> n){
        
        if(!m) break;
         vector<string> str(n, "");
         for(int i = 0; i< m; ++i){
             
             for(int j = 0; j< n; ++j){
                 char t;
                 cin >> t;
                 str[j].push_back(t);
             }
         }
        if(!first)
            cout << endl;
        first = false;
        sort(str.begin(), str.end(), comp2);
        for(int i = 0; i< m; ++i){
            for(int j = 0; j< n; ++j){
                cout <<str[j][i];
            }cout << endl;
        }
    }
    return 0;
}
/*
4 6
a a a a a a
b b b b b b
c c c c c c
x y z X Y a
 
4 6
c C b B a A
b b b b b b
c c c c c c
x y z X Y a
 
3 3
A a a
B a A
c c X
*/

