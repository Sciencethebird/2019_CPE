// D. Pair of Topics_advanced
 
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
 
using namespace std;
int read()
{
    int c=0;int flag=1;
    char s;
    while((s=getchar())>'9'||s<'0')if(s=='-')flag=-1;
    c=s-'0';
    while((s=getchar())<='9'&&s>='0') c=c*10+s-'0';
    return c*flag;
}

int a[200020];
int main(int argc, const char * argv[]) {
   
    int n;
    n =read();
    //vector<int> a(n, 0), b(n, 0), d(n, 0);
 
    for(int i=0;i<n;i++) a[i]=read();
    int k;
    for(int i=0;i<n;i++){
        k=read();
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
