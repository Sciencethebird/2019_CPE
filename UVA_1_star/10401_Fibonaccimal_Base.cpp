//  10401:Fibonaccimal Base

#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <stdlib.h>
using namespace std;


int main(int argc, const char * argv[]) {
    vector<long long> fib;
    vector<long long> bi;
    fib.push_back(1);
    fib.push_back(2);
    bi.push_back(1);
    bi.push_back(2);
    for(int i = 0; i< 40; i++){
        fib.push_back(fib[i]+fib[i+1]);
        bi.push_back( 2*bi[i+1] );
    }
   
    int cases;
    cin >> cases;
    for(int k = 0; k<cases; k++){
        long long N, ans = 0, idx = 40, n;
        cin >> N;
        n = N;
        while(N>0){
            while(fib[idx] > N) idx--;
            ans += bi[idx];
            N -= fib[idx];
        }
        idx = 0;
        //cout << ans << endl;
        bitset<40> temp(ans);
        string t = temp.to_string();
        while(t[idx] != '1') idx++;
        cout << n <<" = "<<t.substr(idx) << " (fib)" << endl;
    }
    return 0;
}
