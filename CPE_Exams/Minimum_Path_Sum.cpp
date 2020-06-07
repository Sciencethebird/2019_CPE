// Minimum Path Sum
 
#include <iostream>

#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <deque>
#include <sstream>
#include <queue>
#include <iomanip>
#include <bitset>
//#include <unordered_map>

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <math.h>

typedef long long ll;
using namespace std;
const int inf = 1<<30;



int main(int argc, const char * argv[]) {
    int cases;
    cin >> cases;
    while(cases--){
        int r, c;
        cin >> r >> c;
        vector<int> temp(c+1, inf);
        vector< vector<int> > mp(r+1, temp);
        
        for(int i = 1; i<= r; i++) for(int j = 1; j<= c; j++){
            scanf("%d", &mp[i][j]);
        }
        
        vector< vector<int> > sum(r+1, temp);
        sum[1][0] = 0;
        
        for(int i = 1; i<= r; i++){
            for(int j = 1; j<= c; j++){
                sum[i][j] = mp[i][j]+min(sum[i-1][j], sum[i][j-1]);
            }
        }
        
        cout << sum[r][c] << endl;
        
        
    }
    
    return 0;
}

