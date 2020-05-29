// 636_C_Two Teams Composing_FTY
 
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
    vector<int> cnt(200010, 0);
    while(cases--){
        
        vector<int> diff_nums;
        int len;
        cin >> len;
        
        vector<int> nums(len);
        int temp;
        for(int i = 0; i< len; i++){
            
            scanf("%d", &temp);
            if(!cnt[temp])
                diff_nums.push_back(temp);
            cnt[temp]++;
        }
        
        int max_idx = 0, max = -1;
        for(auto i : diff_nums){
            if(cnt[i]>max){
                max = cnt[i];
                max_idx = i;
            }
        }
        //cout << max_idx << endl;
        
        
       
        if(diff_nums.size()> cnt[max_idx]){
            cout << cnt[max_idx] << endl;
        }else{
            cnt[max_idx]--;
            cout << std::min(int(diff_nums.size()), cnt[max_idx]) << endl;
        }
            
        
        
        for(auto i : diff_nums){
            cnt[i] = 0;
        }
    }
}
