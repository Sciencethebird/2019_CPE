//
//  main.cpp
//  UVA_2_Star
//
//  Created by Sciencethebird on 2019/7/11.
//  Copyright © 2019 Sciencethebird. All rights reserved.

//  10500:Brick Wall Patterns

#include <iostream>
using namespace std;

long long sum(int num){
    long long sum = 1;
    for(int i = 1; i<= num; i++)
    sum *= i;
    return sum;
}
int main(int argc, const char * argv[]) {
    int brick_num = 0;
    
    while(cin>> brick_num){
        if (brick_num == 0) break;
        long long p = 0;
        for(int i = 0; i*2<=brick_num; i++ ){
            int square = i;
            int indi_block = brick_num - i*2;
            if(indi_block>brick_num){
                
            }else{
                
            }
            p += sum(square+indi_block)/(sum(indi_block)*sum(square));
            //cout << i << endl;
            //cout << "lul" <<sum(square+indi_block)/(sum(indi_block)*sum(square))<< endl;;
        }
        cout << p << endl;
    }
    return 0;
}
