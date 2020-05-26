// 636_C_Alternating Subsequence

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
#include <queue>
#include <iomanip>
#include <bitset>
typedef long long ll;
using namespace std;
const int inf = 1<<30;

int main(int argc, const char * argv[]) {
    int cases;
    cin >> cases;
    while(cases--){
        int len;
        cin >> len;
        vector<int> nums(len);
        for(auto &i:nums){
            cin >> i;
        }
        int max = nums[0];
        bool pos = (nums[0]>0);
        ll sum = 0;
        for(int i = 0; i < len; i++){
            if(pos == (nums[i]>0)){
                if(nums[i]>max){
                    max = nums[i];
                }
            }else{
                sum += max;
                //cout << max << " ";
                max = nums[i];
                pos = !pos;
            }
        }
        //cout << max << endl;
        sum+=max;
        cout << sum << endl;
    }
}
