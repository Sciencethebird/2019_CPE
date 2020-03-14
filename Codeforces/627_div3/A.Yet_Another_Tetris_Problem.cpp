// A.Yet Another Tetris Problem
 
 
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
        cin >> temp;
        bool yn = true;
        int r = temp%2;
        for(int i = 1; i< n; i++){
            cin >> temp;
            if(temp % 2 != r){
                yn = false;
            }
        }
        if(yn)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        
    }
    return 0;
}
