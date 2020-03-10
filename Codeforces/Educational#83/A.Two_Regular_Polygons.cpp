// A. Two Regular Polygons


#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
//#include <string>
//#include <map>
//#include <queue>
//#include <iomanip>
using namespace std;


double nums[3500];
double out[3500];
double co_a[3500];
int N;
//double Cs[3500];


int main(int argc, const char * argv[]) {
    int cases;
    cin >> cases;
    while(cases--){
        int m, n;
        cin >> m >> n;
        if(m%n==0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
