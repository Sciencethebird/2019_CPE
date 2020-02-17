//  10507:Carmichael Numbers Report

#include <iostream>
#include <stdlib.h>
#include <chrono>

typedef std::chrono::high_resolution_clock Clock;
using namespace std;
bool is_multiple[65000] = {true, true, false};
long long num;
long long mod(int a, int power){
    if(power == 1) return a;
    
    long long modvalue =  mod(a, power/2);
    if(power %2 == 0)
        return ( modvalue * modvalue )%num;
    else
        return (( modvalue * modvalue )%num) * a % num;
    
}

int main(int argc, const char * argv[]) {
  
    for(long long i = 2; i < 65000; i++){
        if(!is_multiple[i]){
            for(long long j = i*i; j< 65000; j+=i){
                is_multiple[j] = true;
            }
        }
    }
    auto t1 = Clock::now();
    for(long long n = 0; n< 15000; n++){
        
        num = n;
        bool  pass = true;
        auto t3 = Clock::now();
        if(is_multiple[num]){
            for(long long a = 2; a< num; ++a){
                if(mod(a, num) != a) {
                    pass = false;
                    break; // 1000x time duration if you don't break
                }
            }
        }
        auto t4 = Clock::now();
        if(pass && is_multiple[num])
            printf("The number %lld is a Carmichael number. ", num);
        else
            printf("%lld is normal. ", num);
        cout << (t4 -t3).count() << endl;
    }
    auto t2 = Clock::now();
    cout  << "\n" << (t2 - t1).count() << endl;
    return 0;
}
 






