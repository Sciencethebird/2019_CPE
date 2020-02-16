//  10507:Carmichael Numbers

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <stdlib.h>
#include <deque>
#include <math.h>
#include <algorithm>
#include <fstream>
using namespace std;

int calculated[65000], is_multiple[65000] = {true, true, false};
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
    for(int i = 2; i < 65000; i++){
        if(!is_multiple[i]){
            for(int j = i+i; j< 65000; j+=i){
                is_multiple[j] = true;
            }
        }
    }
    while(cin >> num){
        if(!num) break;
        bool divisable = false, pass = true;
        if(is_multiple[num]){
            for(int a = 2; a< num; a++){
                if(!divisable && num%a==0) divisable = 1;
            
                long long result = mod(a, num);
                if(result != a) {
                    pass = false;
                    break;
                }
            }
        }
        if(divisable && pass)
            cout << "The number " <<num<< " is a Carmichael number." << endl;
        else
            cout << num << " is normal." << endl;
    }
    return 0;
}
 






