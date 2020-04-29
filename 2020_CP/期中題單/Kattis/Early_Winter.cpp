// Early Winter
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
    
  
    int num, dm, cnt = 0;
    bool ok = false;
    cin >> num >> dm;
    while(num--){
        int t;
        cin >> t;
        if(t > dm && !ok){
            cnt++;
        }else{
            ok = true;
        }
    }
    if(!ok){
        cout << "It had never snowed this early!" << endl;
    }else{
        printf("It hadn't snowed this early in %d years!\n", cnt);
    }
    return 0;
}


