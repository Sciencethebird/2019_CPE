//  10504:Garden of Eden

#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <bitset>
using namespace std;

int len, original[40], input[40];
const int dir[8][3] = { {1, 1, 1},
                        {1, 1, 0},
                        {1, 0, 1},
                        {1, 0, 0},
                        {0, 1, 1},
                        {0, 1, 0},
                        {0, 0, 1},
                        {0, 0, 0}};
bool flag = false;
bitset<8> table;

void to_array(string in){
    for(int i = 0 ; i < len; i++){
        input[i] = in[i] - '0';
    }
}

void dfs(int curr){
    if(curr == len){
        if(original[curr] ==original[0] && original[curr+1] == original[1])
            flag = 1;
        return;
    }
    for(int i = 0 ; i< 8; i++){
        if(input[curr] == table[i] && (!curr || (dir[i][0] == original[curr] && dir[i][1] == original[curr+1])) ){
            if(!curr){
                original[0] = dir[i][0];
                original[1] = dir[i][1];
            }
            original[curr+2] = dir[i][2];
            if (flag) return;
            dfs(curr+1);
        }
    }
   
}

int main(int argc, const char * argv[]) {
    
    int id;
    string state;
    while(cin >> id >> len >> state){
        flag = false;
        bitset<8> temp (id);
        table = temp;
        to_array(state);
        dfs(0);
        if(flag)
            cout << "REACHABLE" << endl;
        else
             cout << "GARDEN OF EDEN" << endl;
    }
    return 0;
}
 
