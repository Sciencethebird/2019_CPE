// A. Minimal Square
 
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
        int a, b;
        scanf("%d%d", &a, &b);
        int side = max(max(a, b), 2*min(a, b));
        printf("%d\n", side*side);
        //cout << side*side << endl;
    }
}



