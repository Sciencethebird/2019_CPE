// Careful Ascent

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
typedef long long ll;
using namespace std;


int main(int argc, const char * argv[]) {
    int x, y;
    cin >> x >> y;
    int shd;
    cin >> shd;
    double c = 0;
    ll affected = 0;
    for(int i =0; i<shd; i++){
        ll l, u;
        double mpr;
        cin >> l >> u >> mpr;
        affected += (u - l);
        c+= mpr*(u - l);
    }
    
    
    cout << fixed <<std::setprecision(10)<<x/(y -affected+c)  << endl;
    return 0;
}


/*
-100 140
1
40 90 0.2000000000

 -100 100
 3
 0 20 2.0000000000
 50 100 0.1000000000
 20 50 0.2000000000

 */
