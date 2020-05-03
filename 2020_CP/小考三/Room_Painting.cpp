// Room Painting

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
#include <iomanip>
typedef long long ll;
using namespace std;


int main(int argc, const char * argv[]) {
    int m, n;
    cin >> m >> n;
    vector<int> cans;
    for(int i = 0; i< m; ++i){
        int temp;
        cin >> temp;
        cans.push_back(temp);
    }
    vector<int> colors;
    for(int i = 0; i< n; ++i){
           int temp;
           cin >> temp;
           colors.push_back(temp);
    }
    sort(cans.begin(), cans.end());
    sort(colors.begin(), colors.end());
    ll waste = 0;
    int idx = 0;
    for(int i = 0; i< n; ++i){
        
        while(colors[i] > cans[idx]){
            idx++;
        }
        waste+= (cans[idx] - colors[i]);
    }
    cout << waste << endl;
    return 0;
}


