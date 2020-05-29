// 636_A_Candies

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

int main(int argc, const char * argv[]) {
    int cases;
    cin >> cases;
    while(cases--){
        int num;
        cin >> num;
        for(int i = 2; i< 30; i++){
            //cout << (pow(2, i)-1) << endl;
            if(num%(int)(pow(2, i)-1) == 0){
                cout << num/(int)(pow(2, i)-1) << endl;
                break;
            }
        }
    }
}
