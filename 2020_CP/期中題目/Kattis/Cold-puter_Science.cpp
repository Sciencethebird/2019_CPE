// Cold-puter Science
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

    int num;
    cin >> num;
    int cnt = 0;
    while(num--){
        int t; cin >> t;
        if(t<0){
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}


