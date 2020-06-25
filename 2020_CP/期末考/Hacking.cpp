// Hacking
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
#include <unordered_map>

#include <chrono>
typedef long long ll;
using namespace std;
//using namespace chrono;

int inf = 1<<29;

ll find_max(vector<ll> &nums, ll ub){
    ll mx = 0;
    for(int i = 0; i<ub; i++) if(nums[i]>mx) mx = nums[i];
    return mx;
}
int main(int argc, const char * argv[]) {
    ll P, N;
    scanf("%lld%lld", &P, &N);
    vector<ll> best(P+1, 0);
    for(int i = 0; i< N; i++){
        ll pool, num_ssr;
        scanf("%lld%lld", &pool, &num_ssr);
        best[pool] = find_max(best, pool+1) + num_ssr;
    }
    printf("%lld\n",find_max(best, P+2) );
    return 0;
}
