// D.Pair of Topics_93ms
 
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
 
using namespace std;

int a[200020];
int main(int argc, const char * argv[]) {
   
    int n;
    scanf("%d", &n);
    
 
    for(int i=0;i<n;i++)
        scanf("%d", &a[i]);
    int k;
    for(int i=0;i<n;i++){
        scanf("%d", &k);
        a[i]-=k;
    }
    
    long long count = 0;
    int  r = n -1;
    int sz = n-1;
    sort(a, a+n);
    
    for(int l = 0; l <n; ++l){
        while( l<r && a[l]+a[r]>0){
            --r;
        }
        count += sz-max(r, l);
    }
    
    printf("%lld\n",count);
    return 0;
}
