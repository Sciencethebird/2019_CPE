// B. Collecting Packages_Pairs
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
        int num;
        scanf("%d", &num);
        pair<int, int> z(0, 0);
        vector< pair<int, int> > coords;
        coords.push_back(z);
        for(int i= 0; i< num; ++i){
            int x,y;
            scanf("%d%d", &x, &y);
            coords.push_back({x, y});
        }
        sort(coords.begin(), coords.end());
    
        string out;
        bool ok = true;
        for(int i = 1; i<= num;++i){
            int diffx = coords[i].first - coords[i-1].first;
            int diffy = coords[i].second - coords[i-1].second;
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
