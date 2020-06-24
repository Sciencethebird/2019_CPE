// B. Two Arrays And Swaps
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

bool comp(int a, int b){
    return a>b;
}

int main(int argc, const char * argv[]) {
    int cases;
    scanf("%d", &cases);
    while(cases--){
        int len, swaps, temp;
        scanf("%d%d", &len, &swaps);
        vector<int> a(len), b(len);
        for(int i = 0; i< len; i++){
            scanf("%d", &temp);
            a[i] = temp;
        }
        for(int i = 0; i< len; i++){
            scanf("%d", &temp);
            b[i] = temp;
        }
        sort(a.begin(), a.end(), comp);
        sort(b.begin(), b.end());
        int sum = 0;
        for(int i = len-1; i>=0; i--){
            if(swaps>0){
                if(a[i]<b[i]) sum += b[i];
                else sum += a[i];
                swaps--;
            }
            else{
                sum += a[i];
            }
        }
        printf("%d\n", sum);
    }
}



