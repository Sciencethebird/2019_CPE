// iBoard

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
    
    string buffer;
    while(getline(cin, buffer)){
        int ones = 0, zeros = 0;
        for(auto c:buffer){
            bitset<7> bits(c);
            int temp = bits.count();
            ones += temp;
            zeros += (7-temp);
        }
        if(ones%2 == 0 && zeros%2==0)
            cout << "free" << endl;
        else
            cout << "trapped" << endl;
    }
    return 0;
}

