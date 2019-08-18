//
//  main.cpp
//  UVA_1_Star
//
//  Created by Sciencethebird on 2019/7/12.
//  Copyright © 2019 Sciencethebird. All rights reserved.
//

//24911:Robot Instructions

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

int main(int argc, const char * argv[]) {
    int cases = 0;
    cin >> cases;
    for(int i = 0; i< cases; i++){
        int instrs_n = 0;
        int pos = 0;
        vector<int> instrs(100, 0);
        cin >> instrs_n;
        cin.ignore();
        for(int k = 0; k< instrs_n;k++){
            string input;
            getline(cin, input);
            if(input[0] == 'R'){
                instrs[k] = 1;
                pos++;
            }
            if(input[0] == 'L'){
                instrs[k] = -1;
                pos--;
            }
            if(input[0] == 'S'){
                string temp = input.substr(8);
                int idx = atoi(temp.c_str())-1;
                instrs[k] = instrs[idx];
                pos+=instrs[idx];
            }
        }
        cout << pos << endl;;
    }
    
    return 0;
}

