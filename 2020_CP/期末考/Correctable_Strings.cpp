// Correctable Strings
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
using namespace std;



bool found;
int inf = 1<<29;
//pair<int, int> moves[4] = {{3, 0}, {-2, 3}, {2, -1}, {0, -2}};
//map<pair<int, int>,ll> dis;
string s1, s2;
bool ans;
vector<int> D;
void comp(int s,int len){
    //cout <<D[s+len-1]-D[s];
    if(len>1&&D[s+len]-D[s]<=1) return;
    if(len == 1){
        //cout <<"ff"<< s << endl;
        if(s1[s]!=s2[s]) ans = 0;
        return;
    }
    if(len == 2){
        //cout << s << endl;
        if(s1[s]!=s2[s] && s1[s+1]!=s2[s+1]){
            ans = 0;
        }
        return;
    }
    int half =(len+1)/2;
    comp(s, half);
    comp(s+half, len-half);
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
    

    comp(0, len);
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

