// C. Perform the Combo_fast
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
 
int cnt [26][200010];
char in[200000+10];
inline int read() {
    int x = 0; bool f = true; char c = getchar();
    while (c < '0' || c > '9') {if (c == '-') f = false; c = getchar();}
    while (c >= '0' && c <= '9') x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
    return f ? x : -x;
}
 
int main(int argc, const char * argv[]) {
   
    int cases;
    cin >> cases;
    for(int i = 0; i< 26; ++i)
        cnt[i][0] = 0;
    while(cases--){
        int m, n;
        //string in;
        
        cin >> n >> m;
        
        scanf("%s",in+1);
        
        //vector<int> nums(m+1);
        
        //nums[m] = n;
        //vector<int> temp(n+1, 0);
        //vector< vector<int> > count(26, temp);
        vector<int> sum(26, 0);
        
        /*
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
        }*/
        for(int i = 1; i<= n; ++i){
            for(int c = 0; c<26; ++c){
                cnt[c][i] = cnt[c][i-1];
            }
            cnt[in[i] -'a'][i]++;
        }
        /*
        for(auto i :count){
            for(auto j : i){
                cout << j << " ";
            }cout << endl;
        }*/
        //for(auto i: sum){
            //cout << i << " ";
        //}cout << endl;
        for(int i = 0; i<m; ++i){
            int temp = read();
            //scanf("%d", &temp);
            for(int c = 0; c< 26; ++c){
                sum[c] += cnt[c][temp];
            }
        }
        
        for(int i = 0; i < 26; i++){
            printf("%d ", sum[i] + cnt[i][n]);
        }printf("\n");
    }
    return 0;
}
