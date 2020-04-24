// Problem A Elevator Trouble
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
    
    int f, s, g, u, d, cnt = 0;
    cin >> f >> s >> g >> u >> d;
    int vst = -1;
   
    if(g>s){
        if (u==0){
            cout << "use the stairs"<< endl;
            return 0;
        }
        cnt = (g-s)/u;
        s = cnt*u+s;
    }
    else if(s>g){
        if (d==0){
            cout << "use the stairs"<< endl;
            return 0;
        }
        cnt = (s-g)/d;
        s = s-cnt*d;
    }
    map<int, int> ext;
    while(true){
        //cout << s << endl;
        if(s == g){
            cout << cnt<< endl;
            break;
        }
        if(s< g){
            s+=u;
            if(s>f){
                s-=u;
                s-=d;
                if(s<1){
                    cout << "use the stairs"<< endl;
                    break;
                }
            }
            if(ext.count(s)){
                cout << "use the stairs"<< endl;
                break;
            }
            ext[s] = 0;
            cnt++;
        }
        else if(s>g){
            s-=d;
            cnt++;
            if(s<1) {
                s +=d;
                s +=u;
                if(s>f){
                    cout << "use the stairs"<< endl;
                    break;
                }
            }
            if(ext.count(s)){
                cout << "use the stairs"<< endl;
                break;
            }
            ext[s] = 0;
        }
    }
        

    return 0;
}


