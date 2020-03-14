// B.Yet Another Palindrome Problem
 
 
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
 
using namespace std;
 
int main(int argc, const char * argv[]) {
   
    int cases;
    cin >> cases;
    while(cases--){
        int n;
        cin >> n;
        int temp;
        bool yn = false;
        vector<int> idx(n+1, -1);
        for(int i = 0; i< n; i++){
            cin >> temp;
            
            if(idx[temp]>=0){
                if(i > idx[temp]+1){
                    yn = true;
                }
                continue;
            }
            idx[temp] = i;
        }
        if(yn)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
