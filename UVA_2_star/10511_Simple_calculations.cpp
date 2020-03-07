// 10511:Simple calculations


#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <iomanip>
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
    
        cin >> N;
        
        cin >> nums[0] >> nums[N+1];
        for(int i = 1; i< N+1; i++){
            cin >> nums[i];
        }
        co_a[1] = 1;
        co_a[0] = 0;
        out[1] = 0;
        out[0] = nums[0];
        for(int i = 2; i< N+2; i++){
            co_a[i] = 2*co_a[i-1] - co_a[i-2];
            out[i] = 2*out[i-1] - out[i-2] + 2*nums[i-1];
        }
        printf("%.2f\n", (nums[N+1] - out[N+1])/co_a[N+1] );
        
        if(cases) cout << endl;
    }
    return 0;
}
