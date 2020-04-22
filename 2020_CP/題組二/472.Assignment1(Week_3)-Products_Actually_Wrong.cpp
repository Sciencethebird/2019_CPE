// 472.Assignment1(Week 3)-Products_Actually_Wrong
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <math.h>
#include <sstream>
typedef long long ll;
using namespace std;


int main(int argc, const char * argv[]) {
    string in;
    while(getline(cin, in)){
        stringstream ss;
        ss << in;
        vector<ll> nums;
        
        ll temp;
        while(ss >> temp){
            nums.push_back(temp);
        }
        ll len = nums.size();
        sort(nums.begin(), nums.end());
    
        vector<ll> ans;
        bool ok = true;
        ll pvt = sqrt(nums[0]);
        if(pvt*pvt != nums[0]) ok = false;
        ans.push_back(pvt);
        
        for(int i = 1; i< len; ++i){
            if(nums[i]%pvt == 0){
                ans.push_back(nums[i]/pvt);
                i++;
            }
            if(ans.size()* ans.size()== len){
                break;
            }
        }
        
       
        vector<ll> out;
        for(int i = 0; i<ans.size(); i++){
            for(int j =0; j<ans.size();j++){
                out.push_back(ans[i]*ans[j]);
            }
        }
        sort(out.begin(), out.end());
        for(int i = 1; i< len; ++i){
            if(out[i]!=nums[i]){
                ok = false;
                break;
            }
        }
        if(ok){
            cout << "Yes" << endl;
            for(auto i: ans){
                cout << i <<" ";
            }cout << endl;
        }else{
            cout << "No" << endl;
        }
        
    }
    return 0;
}
