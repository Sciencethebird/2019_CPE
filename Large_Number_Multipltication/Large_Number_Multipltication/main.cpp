//
//  main.cpp
//  Large_Number_Multipltication
//
//  Created by Sciencethebird on 2019/7/11.
//  Copyright © 2019 Sciencethebird. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void mult(string a, string b){
    size_t a_len = a.length();
    size_t b_len = b.length();
    int carry = 0;
    vector<int> result (a_len+b_len, 0);
    for(int i = a_len-1; i>=0; i--){
        int num = a[i] - '0';
        int multpr = b[0] - '0';
       
        
        int sum = num*multpr + carry;
        carry = sum / 10;
        result[i] = sum%10;
        
        cout << result[i] << endl;
    }
    
    for(int i = 0; i< result.size();i++){
        cout << result[i];
    }
    cout << endl;
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    mult("30","5");
    return 0;
}
