// Batter Up
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
typedef long long ll;
using namespace std;


int main(int argc, const char * argv[]) {
    int cases;
    float sum = 0, div = 0;
    cin >> cases;
    while(cases--){
        int num;
        cin >> num;
        if(num>=0) {
            div++;
            sum+=num;
        }
    }
    cout << sum/div << endl;
    return 0;
}


