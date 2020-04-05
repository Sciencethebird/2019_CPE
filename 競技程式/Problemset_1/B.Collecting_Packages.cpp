// B. Collecting Packages
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

struct xy{
    xy():x(0), y(0){}
    xy(int x, int y):x(x), y(y){}
    int x, y;
};
bool compx(const xy &a, const xy &b){
    if(a.x < b.x)return true;
    else return false;
}
bool compy(const xy &a, const xy &b){
    if(a.y < b.y)return true;
    else return false;
}
int main(int argc, const char * argv[]) {
   
    int cases;
    cin >> cases;
    while(cases--){
        int num;
        scanf("%d", &num);
        vector< xy > coords;
        coords.push_back(xy(0,0));
        for(int i= 0; i< num; ++i){
            int x,y;
            scanf("%d%d", &x, &y);
            coords.push_back({x, y});
        }
        sort(coords.begin(), coords.end(), compx);
        stable_sort(coords.begin(), coords.end(), compy);
        //for(auto i : coords) cout << i.x << " "<< i.y << endl;
        string out;
        bool ok = true;
        for(int i = 1; i<= num;++i){
            int diffx = coords[i].x - coords[i-1].x;
            int diffy = coords[i].y - coords[i-1].y;
            if(diffx < 0 || diffy < 0){
                ok = false;
                break;
            }
            while (diffx--) out+='R';
            while (diffy--) out+='U';
        }
        if(ok){
            cout << "YES" << endl;
            cout << out << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}

/*
 for(auto i:sp){
        cout << i << " ";
    }cout << endl;
 */
