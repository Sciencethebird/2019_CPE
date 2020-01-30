//  10413:An Easy Problem

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;
int convert(int c){
    if(c>='0' && c<= '9') {
        c-= '0';
    }else if(c>='A' && c <='Z'){
        c += 10;
        c -= 'A';
    }else if(c>='a' && c <='z'){
        c += 36;
        c -= 'a';
    }
    return c;
}
int main(int argc, const char * argv[]) {
    string num;
    while(cin >> num){
        int sum = 0, ans = -1, max = 0;
        for(int i = 0; i< num.size(); i++){
            int temp = convert(num[i]);
            if( temp > max ) max = temp;
            sum += temp;
        }
        for(int i = max; i<= 63; i++){
            if(sum % i == 0) {
                ans = i + 1;
                break;
            }
        }
        if(ans>=2 && ans <=62)
            cout << ans << endl;
        else
            cout << "such number is impossible!" << endl;
    }
    return 0;
}

/*
Impossible Case
q1234
 */
