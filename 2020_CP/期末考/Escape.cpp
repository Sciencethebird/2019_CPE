// Escape
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
#include <unordered_map>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;



bool found;
int inf = 1<<29;
//pair<int, int> moves[4] = {{3, 0}, {-2, 3}, {2, -1}, {0, -2}};
//map<pair<int, int>,ll> dis;
string s1, s2;
vector<int> D;
ull goal, ans;
ull comb[4] = {4, 4};
void sol(ull pos, ull sum){
    if(pos == goal){
        cout <<sum << endl;
    }
    if(pos+3<=goal){
        
    }if (pos+2<=goal) {
        kkk;
    }
}
int main(int argc, const char * argv[]) {
    
    int len;
    scanf("%d", &len);
    ans = 1;
    cin >> s1 >> s2;
    vector<int> diff(len+1);
    diff[0] = 0;
    diff[1] = (s1[0]!=s2[0]);
    for(int i = 2; i<= len; i++){
        diff[i] = (s1[i-1]!=s2[i-1])+diff[i-1];
    }
    D = diff;
    
    if(ans){
        cout << "True" << endl;
    }else{
        cout << "False" << endl;
    }
    
    return 0;
}

/*
abcefg
xbxefg
 */

