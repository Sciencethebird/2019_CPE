// C.Ehab and Path-etic MEXs
 
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

#define N 110000
using namespace std;

int main(int argc, const char * argv[]) {
    int edges;
    scanf("%d", &edges);
    int a[N], b[N], d[N];
    for(int i = 1; i< edges; i++){
        scanf("%d", &a[i]);
        scanf("%d", &b[i]);
        d[a[i]]++;
        d[b[i]]++;
    }
    int pos =0;
    for(int i = 1; i< edges; i++){
        if(d[i] >=3) pos = i;
    }
    //cout << pos << endl;
    int l = 0, p = edges - 2;
    for(int i = 1; i< edges; i++){
        if(a[i] == pos || b[i] == pos){
            printf("%d\n", l++);
        }else{
            printf("%d\n", p--);
        }
    }
    return 0;
}
