//
//  main.cpp
//  UVA_1_Star
//
//  Created by Sciencethebird on 2019/7/11.
//  Copyright © 2019 Sciencethebird. All rights reserved.
//

/// 22811:Train Swapping
#include <iostream>
using namespace std;

void print(int a[], int len){
    for(int i = 0; i< len; i++)
    cout << a[i] << " ";
    cout << endl;
}
int main(int argc, const char * argv[]) {
    int case_num = 0;
    cin >> case_num;
    for(int i = 0; i< case_num; i++){
        int len = 0;
        cin >> len;
        int train[50] = {};
        for(int j = 0; j< len; j++){
            cin>> train[j];
        }
        int s_count = 0;
        for(int k = len; k>=0; k--){
            for(int l = 0; l<k-1;l++){
                if(train[l]>train[l+1]){
                    std::swap(train[l], train[l+1]);
                    s_count++;
                        //print(train, len);
                }
                
            }
        }
        cout << "Optimal train swapping takes "<<s_count<<" swaps."<< endl;
    }
    return 0;
}

