//  10507:Carmichael Numbers

#include <iostream>
#include <stdlib.h>
 
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
    while( scanf("%lld", &num) != EOF && num != 0 ){
        bool  pass = true;
        if(is_multiple[num]){
            for(long long a = 2; a< num; ++a){
                if(mod(a, num) != a) {
                    pass = false;
                    break;
                }
            }
        }
        if(pass && is_multiple[num])
            printf("The number %lld is a Carmichael number.\n", num);
        else
            printf("%lld is normal.\n", num);
    }
    return 0;
}
 






