//
//  main.cpp
//  UVA_1_Star
//
//  Created by Sciencethebird on 2019/7/12.
//  Copyright © 2019 Sciencethebird. All rights reserved.
//

//10400:The 3n + 1 problem

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

int main(int argc, const char * argv[]) {
    while(1){
        int x1 = 0, x2 = 0;
        if(!(cin >> x1 >> x2)) break;
        //cout << x1 << x2 << endl;
        int t1 = 0, t2 = 0;
        if(x2>=x1) {
            t1 = x1;
            t2 = x2;
        }
        if(x2<x1) {
            t1 = x2;
            t2 = x1;
        }
        long long max_len = 0;
        for(int i = t1; i <= t2; i++){
            long long input = i;
            long long len = 0;
            while(input != 1){
                len ++;
                if(input % 2 == 1) input = 3*input +1;
                else input /=2;
                //cout << input << " ";
            }
            if(len > max_len) max_len = len;
            //cout << i << " "<<len<<endl;
        }
        cout << x1 << " "<< x2 << " " << max_len+1 << endl;
        
    }
    return 0;
}

