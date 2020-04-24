// 472.Assignment1(Week 3)-Products-Correct
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <math.h>
#include <deque>
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
        deque<ll> skip(1, nums[0]);
        
        ll pvt = sqrt(nums[0]);
        if(pvt*pvt != nums[0]) ok = false;
        ans.push_back(pvt);
        
        for(int i = 0; i< len;++i){
            if(ans.size()*ans.size() == len )break;
          
            while(nums[i] == skip.front()){
                i++;
                skip.pop_front();
                
            }
            if(nums[i]%pvt ==0){
                ll nw = nums[i]/pvt;
                for(int l = 1; l<ans.size(); ++l){
                    skip.push_back(ans[l]*nw);
                    skip.push_back(ans[l]*nw);
                }
                skip.push_back(nw*nw);
                ans.push_back(nw);
                i++;
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

// WA case:
// 7
// No
// cuz not seperable


// Spectial case: not actually wa, the judge didn't know it
// 1 1 3 1 1 3 3 3 9
// 4 4 6 4 4 6 6 6 9
// 1 1 1 3

// 1 1 1 3 1 1 1 3 1 1 1 3 3 3 3 9
// 1 2 2 3 3
// 1 2 2 3 3 2 4 4 6 6 2 4 4 6 6 3 6 6 9 9 3 6 6 9 9
