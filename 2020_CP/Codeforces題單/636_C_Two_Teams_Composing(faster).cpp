// 636_C_Two Teams Composing(faster)

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

inline int read() {int x=0,f=1;char c=getchar();while(c!='-'&&(c<'0'||c>'9'))c=getchar();if(c=='-')f=-1,c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return f*x;}


int main(int argc, const char * argv[]) {
    int cases;
    //cin >> cases;
    cases = read();
    vector<int> cnt(200010, 0);
    while(cases--){
        
        //vector<int> diff_nums;
        int len;
        len = read();
        //scanf("%d", &len);
        for(int i = 0; i<=len; i++){
            cnt[i] = 0;
        }
        //vector<int> nums(len);
        int temp;
        int max_num = 0, max_cnt = -1, num_of_diff_nums = 0;
        for(int i = 0; i< len; i++){
            //scanf("%d", &temp);
            temp = read();
            if(!cnt[temp])
                num_of_diff_nums++;
            
            cnt[temp]++;
            if(cnt[temp] > max_cnt){
                max_cnt = cnt[temp];
                max_num = temp;
            }
        }
        
        if(num_of_diff_nums> cnt[max_num]){
            printf("%d\n",cnt[max_num]  );
        }else{
            cnt[max_num]--;
            printf("%d\n", std::min(num_of_diff_nums, cnt[max_num]) );
        }
    }
}
