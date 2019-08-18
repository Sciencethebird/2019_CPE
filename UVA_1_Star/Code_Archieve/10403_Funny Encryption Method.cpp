//
//  main.cpp
//  UVA_1_Star
//
//  Created by Sciencethebird on 2019/7/17.
//  Copyright © 2019 Sciencethebird. All rights reserved.
//

// 10403:Funny Encryption Method

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <bitset>
#include <sstream>
using namespace std;

int main(int argc, const char * argv[]) {
    int cases = 0;
    cin >> cases;
    for(int i = 0; i< cases; i++){
        int num = 0, hex_num = 0;
        stringstream conv;
        cin >> num;
        conv << num;
        conv >> std::hex >>hex_num;
        string n1 = bitset<16>(num).to_string();
        string hex = bitset<16>(hex_num).to_string();
        int b1 = 0, b2 = 0;
        for(int i = 0; i<16;i++){
            if(n1[i] == '1') b1++;
            if(hex[i] == '1') b2++;
        }
        cout << b1 << " " << b2 << endl;
    }

    return 0;
}
    

