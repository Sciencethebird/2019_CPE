//
//  main.cpp
//  UVA_1_Star
//
//  Created by Sciencethebird on 2019/7/17.
//  Copyright © 2019 Sciencethebird. All rights reserved.
//

// 10410:Tell me the frequencies!

#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <bitset>
#include <algorithm>
#include <sstream>
using namespace std;
bool cpr(const vector<int>  &a, const vector<int> &b){
    if (a[1] == b[1]) return a[0]>b[0];
    return a[1]<b[1];
}

int main(int argc, const char * argv[]) {
    string input;
    bool start = false;
    while(cin >> input){
        if(start) cout <<endl;
        start = true;
        vector<int> int_form ;
        //cout << input << endl;
        for(int i = 0; i< input.size(); i++){
            int_form.push_back(input[i]);
        }
      
        std::sort(int_form.begin(), int_form.end());
        
     
        
        int curr_val = -1;
        
        vector< vector<int> > cnt;
        for(int i = 0; i< int_form.size(); i++){
            if(curr_val == int_form[i]) continue;
            vector<int> temp;
            temp.push_back(int_form[i]);
            temp.push_back(std::count(int_form.begin(), int_form.end(), int_form[i]));
            cnt.push_back(temp);
            curr_val = int_form[i];
        }
        
        sort(cnt.begin(), cnt.end(),cpr );
        for(int i = 0; i< cnt.size(); i++){
            cout << cnt[i][0] << " " << cnt[i][1] << endl;
        }
        
    }
    return 0;
}
