// C. Board Moves
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
    
    vector<ull> val(500001);
    //int dis = 0;
    for(ull i = 0; i<=500001; i++){
        val[i] = ((i*2)*4*i);
    }
    
    int cases;
    scanf("%d", &cases);
    
    while(cases--){
        int len = 0;
        scanf("%d", &len);
        ull sum = 0;
        int ub = (len+1)/2;
        for(int i = 0; i<ub;i++){
            sum+=val[i];
        }
        printf("%llu\n", sum);
        //cout << sum << endl;
    }
    return 0;
}

/*
 3 4 6 9
 3 4 6 9 x
 3 9 4 6 o
 */

