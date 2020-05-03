// Bits

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

int main(int argc, const char * argv[]) {
    int cases;
    cin >> cases;
    //int prev = 0;
    while(cases--){
        ll num, div = 1, max = 0;
        cin >> num;
        while(div <= num){
            
            bitset<35> bits(num/div);
            if(bits.count()>max) max = bits.count();
            //cout << num/div <<" "<<max << endl;
            div*=10;
        }
        bitset<35> bits(num/div);
        if(bits.count()>max) max = bits.count();
        cout << max << endl;
    }
    return 0;
}

// 2147483647
