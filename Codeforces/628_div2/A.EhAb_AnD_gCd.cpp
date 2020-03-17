// A.EhAb AnD gCd
 
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
    scanf("%d", &cases);
    while(cases--){
        int num;
        scanf("%d", &num);
        for(int i = 1; i< num; i++){
            if((num - i) % i == 0){
                printf("%d %d\n", i, num -i);
                break;
            }
        }
    }
    return 0;
}
