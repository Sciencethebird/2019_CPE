// Suspension Bridges

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
    double d, s;
    cin >> d >> s;
    double a = 1, pc = 0.1, up= 1.1, down = 0.9;
    for(int i = 0; i< 10000000; i++){
        double now = a*cosh(d/(2*a)) - a;
        if( now > s) a*=up;
        else if (now< s) a*=down;
        //cout << pc << endl;
        if(fabs(now -s)<pc){
            pc*=0.1;
            up = 1+pc;
            down = 1-pc;
        }
    }
    //cout << a*cosh(d/(2*a)) - a << endl;
    cout <<fixed<<setprecision(6)<< 2*a*sinh(d/(2*a)) << endl;
}


/*
14 5
1
1
1
1
1
1
1
1
1
1
1
1
1
1
*/
