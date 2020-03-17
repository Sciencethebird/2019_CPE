// B.CopyCopyCopyCopyCopy
 
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
        int len;
        scanf("%d", &len);
        map<int, bool> exist;
        int diff_count = 0;
        for(int i = 0; i< len; i++){
            int temp;
            scanf("%d", &temp);
            if(!exist[temp]){
                exist[temp] = 1;
                diff_count++;
            }
        }
        printf("%d\n", diff_count);
    }
    return 0;
}
