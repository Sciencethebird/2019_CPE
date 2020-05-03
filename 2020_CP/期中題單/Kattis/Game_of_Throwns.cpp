// Game of Throwns

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
#include <bitset>
typedef long long ll;
using namespace std;

int main(int argc, const char * argv[]) {
    int n, cases;
    cin >> n >> cases;
    vector<int> pos(1, 0), prev(1, 0);
    int curr = 0;
    for(int i = 0; i< cases; i++){
        string in;
        cin >> in;
        if(in[0] == 'u'){
            int temp;
            cin >> temp;
            for(int k = 0; k<temp; k++){
                curr = prev[curr];
            }
        }else{
            int move = stoi(in);
            move%=n;
            move+= pos[curr];
            if(move < 0){
                move+= n;
            }
            move%=n;
            pos.push_back(move);
            prev.push_back(curr);
            curr = pos.size()-1;
        }
        /*
        for(auto i:pos){
            cout << i << " ";
        }cout << endl;*/
    }
    
    if(curr!= pos.size()-1){
        pos.push_back(pos[curr]);
    }
    cout << pos.back() << endl;
    return 0;
}

/*
20 10
3 4 undo 1 3 undo 1 5
 */
