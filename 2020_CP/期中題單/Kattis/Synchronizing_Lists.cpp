// Synchronizing Lists

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
    int num;
    while(cin >> num){
        map<int, int> lst;
        if(!num) break;
        vector<int> in, sorted;
        for(int i = 0; i< num; ++i){
            int temp;
            cin >> temp;
            in.push_back(temp);
            sorted.push_back(temp);
            lst[temp] = 0;
        }
        int idx = 0;
        for(auto& e : lst){
            e.second = idx;
            idx++;
        }
        
        vector<int> out;
        for(int i = 0; i< num; ++i){
            int temp;
            cin >> temp;
            out.push_back(temp);
        }
        sort(out.begin(), out.end());
        for(int i = 0; i< num; ++i){
            cout <<out[lst[in[i]]]<< endl;
        }
        cout << endl;
    }
             
        
    return 0;
}



