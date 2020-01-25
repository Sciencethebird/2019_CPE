//  10404:Primary Arithmetic

#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <sstream>
#include <algorithm> // std::sort

using namespace std;


int main(int argc, const char * argv[]) {
    long long a, b;
    while(cin >> a >> b){
        if(a == 0 && b == 0) break;
        int carry = 0;
        int carry_num = 0;
        while(a != 0 || b != 0 || carry != 0){
            int a_last = a % 10, b_last = b % 10;
            carry = carry + a_last + b_last;
            carry /= 10;
            a /= 10;
            b /= 10;
            if(carry) carry_num++;
        }
        if(carry_num>1)
            cout << carry_num << " carry operations." << endl;
        else if(carry_num == 1)
            cout << "1 carry operation." << endl;
        else
            cout << "No carry operation." << endl;
    }
    return 0;
}
