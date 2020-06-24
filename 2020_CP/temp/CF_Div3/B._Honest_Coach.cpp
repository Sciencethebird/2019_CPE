// B. Honest Coach
 
#include <iostream>

#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <deque>
#include <sstream>
#include <queue>
#include <iomanip>
#include <bitset>
#include <unordered_map>

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <math.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int inf = 1<<30;



int main(int argc, const char * argv[]) {
    int cases;
    scanf("%d", &cases);
    while(cases--){
        int len, temp;
        scanf("%d", &len);
        vector<int> nums(len);
        for(int i = 0; i<len; i++){
            scanf("%d", &temp);
            nums[i] = temp;
        }
        std::sort(nums.begin(), nums.end());
        int diff = inf;
        for(int i = 1; i< len; i++){
            if(nums[i]-nums[i-1]<diff){
                diff = nums[i]-nums[i-1];
            }
        }
        printf("%d\n", diff);
    }
}



