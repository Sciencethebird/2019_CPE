//
//  main.cpp
//  UVA_1_Star
//
//  Created by Sciencethebird on 2019/7/12.
//  Copyright © 2019 Sciencethebird. All rights reserved.
//

// 10401:Fibonaccimal Base

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

int main(int argc, const char * argv[]) {
    vector<long long> fib;
    fib.push_back(1);
    fib.push_back(2);
    for(int i = 2; i<50;i++){ fib.push_back(fib[i-1]+fib[i-2]);
    }
    int cases = 0;
    cin >> cases;
    for(int i = 0; i< cases; i++){
        long long input;
        string ans = "";
        cin >> input;
        long long sum = 0;
        for(int idx = 48; idx>=0; idx--){
            if(sum + fib[idx] > input){
                ans += '0';
            }
            if(sum + fib[idx] < input) {
                sum += fib[idx];
                ans += '1';
            }
            if(sum + fib[idx] == input) {
                sum += fib[idx];
                ans += '1';
            }
        }
        cout << input <<" = "<<ans.substr(ans.find("1")) +" (fib)" << endl;
    }
    return 0;
}

