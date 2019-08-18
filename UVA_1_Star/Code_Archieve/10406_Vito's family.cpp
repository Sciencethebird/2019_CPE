//
//  main.cpp
//  UVA_1_Star
//
//  Created by Sciencethebird on 2019/7/17.
//  Copyright © 2019 Sciencethebird. All rights reserved.
//

// 10406:Vito's family

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <bitset>
#include <algorithm>
#include <sstream>
using namespace std;

int main(int argc, const char * argv[]) {
    int cases = 0;
    cin >> cases;
    for(int i = 0; i<cases; i++){
        int len = 0;
        cin >> len;
        vector<int> numbers(len, 0);
        //cout << len << endl;
        for(int j = 0; j<len; j++){
            cin >> numbers[j];
        }
        //cout << numbers.size() << endl;
     
        std::sort(numbers.begin(), numbers.end());
        //cout << numbers.size() << endl;
  
        int min = numbers[0], max = numbers.back();
        long long min_dis = 0;
        long long limit = numbers.size();
        for(int l = 0; l < limit; l++){
            min_dis += labs(min - numbers[l]);
        }
        for(int k = min; k<max; k++){
            long long d = 0;
            
            for(int l = 0; l < limit; l++){
                d += labs(k - numbers[l]);
            }
            if(d<min_dis){
                min_dis = d;
            }
        }
        cout << min_dis << endl;
    }
    return 0;
}
