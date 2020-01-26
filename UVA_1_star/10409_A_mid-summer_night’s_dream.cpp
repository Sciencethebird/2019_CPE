//  10409:A mid-summer night’s dream

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main(int argc, const char * argv[]) {
    int cases;
    while(cin >> cases){
        vector<int> nums(cases, 0);
        for(int i = 0; i< cases; i++) cin >> nums[i];
       
        sort(nums.begin(), nums.end());
        int mid = (cases-1)/2, right;
        if (cases%2 == 0) right = mid+1;
        else right = mid;
        int in_nums = 0;
        for(int i = 0; i< cases; i++){
        if(nums[i] >= nums[mid] && nums[i]<= nums[right]) in_nums++;
        }
        cout << nums[mid] <<" "<<in_nums<<" "<< nums[right] - nums[mid] + 1 << endl;
    }
    return 0;
}
