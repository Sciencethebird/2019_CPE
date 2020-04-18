// C.Perform the Combo_first_try

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <math.h>
typedef long long ll;
using namespace std;
 

int main(int argc, const char * argv[]) {
   
    int cases;
    cin >> cases;
    while(cases--){
        int m, n;
        //string in;
        
        cin >> n >> m;
        char in[200000+10];
        scanf("%s",in);
        
        //vector<int> nums(m+1);
        
        for(int i = 0; i< m; ++i){
            //scanf("%d", &nums[i]);
        }
        //nums[m] = n;
        vector<int> temp(n, 0);
        vector< vector<int> > count(26, temp);
        vector<int> sum(26, 0);
        for(int c = 0; c<26; ++c){
            if(in[0] == c+'a')
                count[c][0]++;
            for(int i = 1; i< n; ++i){
                if(in[i] == c+'a')
                    count[c][i]++;
                count[c][i] += count[c][i-1];
            }
            //cout << count[c].back() << endl;
            sum[c] = count[c].back();
        }
        
        for(int i = 0; i<m; ++i){
            int temp;
            scanf("%d", &temp);
            for(int c = 0; c< 26; ++c){
                sum[c] += count[c][temp-1];
            }
        }
        
        for(auto i: sum){
            cout << i << " ";
        }cout << endl;
    }
    return 0;
}
