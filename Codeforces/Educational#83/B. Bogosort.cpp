// B. Bogosort


#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <vector>
#include <algorithm>
//#include <string>
#include <map>
//#include <queue>
//#include <iomanip>
using namespace std;


bool comp(int a, int b){
    return a > b;
}
int main(int argc, const char * argv[]) {
   
    int cases;
    cin >> cases;
    while(cases--){
        int len;
        cin >> len;
        vector<int> nums(len);
        for(int i = 0; i< len; ++i){
            cin >> nums[i];
        }
        sort(nums.begin(), nums.end(), comp);
       
        for(int i = 0; i< len; ++i){
            cout << nums[i] << " ";
        }cout << endl;
    }
    
    return 0;
}
