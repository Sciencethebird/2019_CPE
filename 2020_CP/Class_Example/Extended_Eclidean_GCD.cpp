// Extended_Eclidean_GCD
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


void gcd(ll a, ll b, ll mod_inv = 1){
    ll k = 0;
    
    while(a>0){
        a-=b;
        k++;
    }
    if(a==0) {
        cout << b << endl;
        return;
    }
    gcd(b, a+b);
}

void mod_inv(ll a, ll b){
    ll k = 0;
    
    while(a>0){
        a-=b;
        k++;
    }
    if(a==0) {
        cout << b << endl;
        return;
    }
    gcd(b, a+b);
}
int main(int argc, const char * argv[]) {
    ll a, b;
    cin >> a >> b;
    if(b>a) swap(a, b);
    gcd(a, b);
}
