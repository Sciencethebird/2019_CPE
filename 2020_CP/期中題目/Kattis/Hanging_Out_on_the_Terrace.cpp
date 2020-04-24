// Hanging Out on the Terrace
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
    
    int n, cases, curr = 0, ans = 0;
    cin >> n >> cases;
    while(cases--){
        string in;
        int num;
        cin >> in >> num;
        if(in[0] == 'e'){
            if(curr+num>n){
                ans++;
            }else{
                curr+=num;
            }
        }else if(in[0] == 'l'){
            curr-= num;
        }
    }
    cout << ans << endl;
    return 0;
}


