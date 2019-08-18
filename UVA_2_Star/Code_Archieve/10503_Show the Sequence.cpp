//
//  main.cpp
//  UVA_2_Star
//
//  Created by Sciencethebird on 2019/7/11.
//  Copyright © 2019 Sciencethebird. All rights reserved.

//  10503:Show the Sequence

#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main(int argc, const char * argv[]) {
    string input;
    while(getline(cin, input)){
        int idx = (int)input.size() - 1;
        while(input[idx]== ' '){
            idx--;
        }
        string t = "";
        while(input[idx] != ' '){
            t = input[idx]+t;
            idx--;
        }
        int seq_len = atoi(t.c_str());
        idx --;
        int layers = 0;
      
        while(input[idx] == ']'){
            layers++;
            idx--;
        }
        vector<long long> temp(seq_len,0);
        vector<vector<long long> > seqs(layers,temp);
        t = "";
        while(input[idx] != '['){
            t = input[idx]+t;
            idx--;
        }
        long long n = atoll(t.c_str());
        for(int i1 = 0; i1< seq_len; i1++){
            seqs[0][i1] = n;
        }
        idx --;
        int row_idx = 1;
        while(idx> 0){
            char optr = input[idx];
            idx--; t = "";
            while(input[idx]!='['){
                t = input[idx]+t;
                idx--;
            }
            idx--;
            long long number = atoll(t.c_str());
            if(optr == '+'){
                seqs[row_idx][0] = number;
                for(int j = 1; j< seq_len; j++){
                    seqs[row_idx][j]
                    = seqs[row_idx][j-1] + seqs[row_idx-1][j-1];
                }
            }
            if(optr == '*'){
                seqs[row_idx][0] = number*seqs[row_idx-1][0];
                for(int j = 1; j< seq_len; j++){
                    seqs[row_idx][j]
                    = seqs[row_idx][j-1] * seqs[row_idx-1][j];
                }
            }
            row_idx++;
        }
        int last = seqs.size()-1;
        for(int s = 0; s<seq_len; s++){
            cout << seqs[last][s];
            if(s == seq_len-1)  cout << endl;
            else cout << " ";
        }
    }
    return 0;
}

