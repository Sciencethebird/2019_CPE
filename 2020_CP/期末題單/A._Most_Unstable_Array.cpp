// A. Most Unstable Array
 
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
        int n, m;
        scanf("%d%d", &n, &m);
        if(n==1){
            printf("0\n");
        }else if (n==2){
            printf("%d\n", m);
        }else{
            printf("%d\n", 2*m);
        }
    }
    return 0;
}


