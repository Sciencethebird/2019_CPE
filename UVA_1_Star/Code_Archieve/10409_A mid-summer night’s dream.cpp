//
//  main.cpp
//  UVA_1_Star
//
//  Created by Sciencethebird on 2019/7/17.
//  Copyright © 2019 Sciencethebird. All rights reserved.
//

// 10409:A mid-summer night’s dream

#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <bitset>
#include <algorithm>
#include <sstream>
using namespace std;

int main(int argc, const char * argv[]) {
    int num_num = 0;
    while(cin >> num_num){
        vector<int> nums(num_num, 0);
        int ans_pos = 0;
        for(int i = 0; i< num_num; i++){
            cin >> nums[i];
        }
        sort(nums.begin(), nums.end());
        long long sum = 0;
        long long min =  140732920755544;
        long long A = 0;
        for(int i = 0; i<= nums.back(); i++){
            for(int j = 0; j< nums.size(); j++){
                sum += labs(i-nums[j]);
            }
            if(sum == min){
                ans_pos++;
            }
            if(sum <min){
                min = sum;
                A = i;
                ans_pos = 0;
                ans_pos++;
            }
            sum = 0;
        }
        int same = 0;
        for(int j = 0; j< nums.size(); j++){
            if(nums[j] == A)
                same++;
        }
        //cout << ans_pos << endl;
        cout << A << " " << same <<" "<< ans_pos <<endl;
    }
    
    return 0;
}
