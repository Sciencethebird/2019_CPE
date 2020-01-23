//  24921:Guard the Land

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;

enum {x1 = 0, y1, x2, y2};

int main(int argc, const char * argv[]) {
    
    
    int cases;
    cin >> cases;
    
    int a[2][4];
    for(int k = 0; k<cases; k++){
        for(int i = 0; i< 4; i++)
            cin >> a[0][i];
        for(int i = 0; i< 4; i++)
            cin >> a[1][i];
        
        int hlen = 0, vlen = 0;
        
        // horizontal
        if(a[0][x1] <= a[1][x1] && a[1][x1] <= a[0][x2]){
            if(a[1][x2]<=a[0][x2]) hlen = a[1][x2] - a[1][x1];
            else hlen = a[0][x2] - a[1][x1];
        }
        if(a[1][x1] <= a[0][x1] && a[0][x1] <= a[1][x2]){
            if(a[0][x2]<=a[1][x2]) hlen = a[0][x2] - a[0][x1];
            else hlen = a[1][x2] - a[0][x1];
        }
        //cout << hlen << endl;
        if(a[0][y1] <= a[1][y1] && a[1][y1] <= a[0][y2]){
            if(a[1][y2]<=a[0][y2]) vlen = a[1][y2] - a[1][y1];
            else vlen = a[0][y2] - a[1][y1];
        }
        if(a[1][y1] <= a[0][y1] && a[0][y1] <= a[1][y2]){
            if(a[0][y2]<=a[1][y2]) vlen = a[0][y2] - a[0][y1];
            else vlen = a[1][y2] - a[0][y1];
        }
        //cout << vlen << endl;
        int ssr = vlen * hlen;
        int a1 =  (a[0][x2] - a[0][x1])*(a[0][y2] - a[0][y1]);
        int a2 =  (a[1][x2] - a[1][x1])*(a[1][y2] - a[1][y1]);
        cout << "Night "<< k+1 <<": " << ssr <<" "<< a1 + a2 - 2*ssr <<" "<< 10000 - a1 - a2 + ssr << endl;
    }

    return 0;
}
