//
//  main.cpp
//  UVA_1_Star
//
//  Created by Sciencethebird on 2019/7/17.
//  Copyright © 2019 Sciencethebird. All rights reserved.
//

// 10404:Primary Arithmetic

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <bitset>
#include <sstream>
using namespace std;

int main(int argc, const char * argv[]) {
    string n1, n2;
    while(1){
        cin >> n1 >> n2 ;
        if(n1 == "0" && n1 == n2) break;
        if(n1.length() < n2.length()){
            std:: swap(n1, n2);
        }
        //cout << n1 << " " << n2 << endl;
        int carry = 0, carry_cnt = 0;
        int diff = n1.length() - n2.length();
        for(int i = n1.length()-1; i>= diff; i--){
            carry = (carry + n1[i]+n2[i-diff] - 2*'0')/10;
            if(carry) carry_cnt ++;
        }
        for(int i = diff-1; i>= 0; i--){
            carry = (carry + n1[i] - '0')/10;
            if(carry) carry_cnt ++;
        }
        if (carry_cnt == 0) cout << "No carry operation." << endl;
        else if (carry_cnt == 1) cout << "1 carry operation." << endl;
        else cout << carry_cnt << " carry operations." << endl;
    }
    return 0;
}

