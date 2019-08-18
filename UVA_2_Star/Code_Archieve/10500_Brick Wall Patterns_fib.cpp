//
//  main.cpp
//  UVA_2_Star
//
//  Created by Sciencethebird on 2019/7/11.
//  Copyright © 2019 Sciencethebird. All rights reserved.

//  10500:Brick Wall Patterns

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int brick_num = 0;
    
    while(cin>> brick_num){
        if (brick_num == 0) break;
        long long p[50] ={1, 2};
    
        for(int i = 2; i<brick_num; i++ ){
            p[i] = p[i-1]+p[i-2];
        }
        cout << p[brick_num-1] << endl;
    }
    return 0;
}

