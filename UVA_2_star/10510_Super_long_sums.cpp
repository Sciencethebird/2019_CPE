//  10510:Super long sums

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <map>
#include <queue>
using namespace std;

int num[1000000][2];
int sum[1000000];

int main(int argc, const char * argv[]) {
    int cases;
    cin >> cases;
    
    while(cases--){
        int M;
        cin >> M;
        for(int i= 0; i< M; i++){
            cin >> num[i][0] >> num[i][1];
        }
        int carry = 0;
        for(int i = M-1; i>=0; --i){
            sum[i] = carry + num[i][0]+ num[i][1];
            carry = sum[i] / 10;
            sum[i] %= 10;
        }
        for(int i = 0; i <M; ++i){
            cout << sum[i] ;
        }cout << endl;
        if(cases){
            cout << endl;
        }
    }
    return 0;
}
 


