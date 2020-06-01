// 629_C_Ternary XOR
 
#include <iostream>

#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <deque>
#include <sstream>
#include <queue>
#include <iomanip>
#include <bitset>
#include <unordered_map>

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <math.h>

typedef long long ll;
using namespace std;
const int inf = 1<<30;



int main(int argc, const char * argv[]) {
    int cases;
    cin >> cases;
    while(cases--){
        int len;
        string num, big, small;
        cin >> len >> num;
        bool bigger = false;
        for(int i = 0; i<len;i++){
            if(num[i] == '0'){
                big.push_back('0');
                small.push_back('0');
            }else if(num[i] == '1'){
                if(!bigger){
                    big.push_back('1');
                    small.push_back('0');
                    bigger = true;
                }else{
                    big.push_back('0');
                    small.push_back('1');
                }
            }else if (num[i] == '2'){
                if(!bigger){
                    big.push_back('1');
                    small.push_back('1');
                }else{
                    big.push_back('0');
                    small.push_back('2');
                }
            }
        }
        cout << big << endl;
        cout << small << endl;
    }
    
    return 0;
}

