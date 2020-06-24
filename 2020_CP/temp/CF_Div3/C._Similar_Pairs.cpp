// C. Similar Pairs
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
        int len, temp, odd_count = 0, even_count = 0;
        scanf("%d", &len);
        vector<int> a(len);
        for(int i = 0; i< len; i++){
            scanf("%d", &temp);
            a[i] = temp;
            if(temp%2==0) even_count++;
            else odd_count++;
        }
        sort(a.begin(), a.end());
        int pair_count = 0;
        for(int i = 1; i< a.size(); i++){
            if(a[i] == a[i-1]+1){
                pair_count++;
                break;
            }
        }
        if(even_count%2==0 && odd_count%2==0){
             printf("YES\n");
        }
        else if(even_count%2==1 && odd_count%2==1){
            if(pair_count)
                printf("YES\n");
            else
                printf("NO\n");
        }else{
            printf("NO\n");
        }
    }
    return 0;
}

/*
 3 4 6 9
 3 4 6 9 x
 3 9 4 6 o
 */

