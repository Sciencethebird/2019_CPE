// Cantor

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
    double num;
    while(cin >> num){
        bool ok = true;
        if(num == 1) {
            cout <<"MEMBER" << endl;
            continue;
        }
        for(int i = 0; i< 30; i++){
            
            int f = (int) num;
            //cout << i << endl;
            if(f == 1) {
                ok = false;
                break;
            }
            
            num -=f;
            num*=3;
        }
        if(ok){
            cout << "MEMBER" << endl;
        }else{
            cout <<"NON-MEMBER" << endl;
        }
        
    }
    return 0;
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
