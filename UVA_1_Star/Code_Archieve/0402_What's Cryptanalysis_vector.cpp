//
//  main.cpp
//  UVA_1_Star
//
//  Created by Sciencethebird on 2019/7/17.
//  Copyright © 2019 Sciencethebird. All rights reserved.
//

// 10402:What's Cryptanalysis?

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int lines = 0;
    cin>> lines;
    
    string input = "";
    cin.ignore();
    
    for(int i = 0; i<lines; i++){
        string buffer;
        getline(cin, buffer);
        input +=buffer;
    }
    //cout << input << endl;
    size_t len = input.length();
    for(int i = 0; i< len; i++){
        input[i] = toupper(input[i]);
    }
    //cout << input << endl;
    vector<int> counts(26, 0);
    vector<int> idx(26, 0);
    for(int i = 0; i<26; i++){
        idx[i] = i;
    }
    for(int i = 0; i< len; i++){
        if(input[i] - 'A' > 26 ||input[i] - 'A' < 0 ) continue;
        counts[input[i] - 'A']++;
    }

    for(int i = 0; i< 26; i++){
        for(int j = i+1; j<26; j++){
            if(counts[i]>counts[j]){
                std::swap(counts[i], counts[j]);
                std::swap(idx[i], idx[j]);
            }
            if(counts[i] == counts[j]){
                if(idx[i] < idx[j]){
                    std::swap(counts[i], counts[j]);
                    std::swap(idx[i], idx[j]);
                }
            }
        }
    }
    for(int i = 25; i>=0;i--){
        if(counts[i]!=0){
            cout << (char)('A'+idx[i]) << " ";
            cout << counts[i] << endl;
        }
    }
    return 0;
}
    

