// C.Frog Jumps
 
 
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
        string dir;
        cin >> dir;
        dir = 'R' + dir + 'R';
        int min = 0, idx = 0;
        for(int i = 0; i< dir.size(); i++){
            if(dir[i] == 'R'){
                if(i - idx > min){
                    min = i - idx;
                }
                idx = i;
            }
        }
        cout << min << endl;
    }
    return 0;
}
