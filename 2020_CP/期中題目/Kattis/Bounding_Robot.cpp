// Bounding Robot
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <math.h>
#include <deque>
#include <sstream>
typedef long long ll;
using namespace std;


int main(int argc, const char * argv[]) {
    int m, n;
    while(cin >> m >> n){
        int num;
        if(!m && !n){
            break;
        }
        cin >> num;
        
        int rx = 0, ry = 0, ax = 0, ay = 0;
        while(num--){
            char dir;
            int d;
            cin >> dir >> d;
            if(dir =='u'){
                ry+=d;
                ay+=d;
                if(ay >=n) ay = n-1;
            }else if(dir =='d'){
                ry-=d;
                ay-=d;
                if(ay <0) ay = 0;

            }else if(dir =='r'){
                rx+=d;
                ax+=d;
                if(ax >=m) ax = m-1;
            }else if(dir =='l'){
                rx-=d;
                ax-=d;
                if(ax <0) ax = 0;
            }
        }
        cout << "Robot thinks " <<rx <<" " << ry << endl;
        cout <<"Actually at "<< ax <<" " << ay << endl<< endl;
    }
    return 0;
}


