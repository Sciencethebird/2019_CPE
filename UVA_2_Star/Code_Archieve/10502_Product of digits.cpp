//
//  main.cpp
//  UVA_2_Star
//
//  Created by Sciencethebird on 2019/7/11.
//  Copyright © 2019 Sciencethebird. All rights reserved.

//  10502:Product of digits

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    int cases = 0;
    cin >> cases;
    for(int i = 0; i< cases; i++){
        long long num;
        cin >> num;
        vector<int> facs;
        int divider = 9;
        bool valid = false;
        if(num ==1){
            cout << 1 << endl;
            continue;
        }
        while(divider!=1){
            if(num == 1){
                valid = true;
                break;
            }
            if(num % divider == 0){
                facs.push_back(divider);
                num /= divider;
            }else{
                divider--;
            }
        }
        if(valid){
            for(int k = (int)facs.size() -1; k>=0; k--){
                cout << facs[k];
            }cout << endl;
        }else if(!valid) cout << -1 << endl;
        
    }
    return 0;
}

