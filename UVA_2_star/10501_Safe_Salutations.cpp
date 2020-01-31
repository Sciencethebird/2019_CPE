//  10501:Safe Salutations

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main(int argc, const char * argv[]) {
    
    vector<int> ans(10, 0);
    ans[0] = 1; ans[1] = 1; ans[2] = 2;
    
    // calculate first
    for(int i = 3; i<= 10; i++){
        int temp = 0;
        for(int j = 1; j<=i; j++)
            temp += ( ans[j-1] * ans[i-j] );
        ans[i] = temp;
    }
    bool start = false; // keep last case from printing endl
    int pairs;
    while(cin>> pairs){
        if(start) cout << endl;
        cout << ans[pairs] << endl;
        start = true;
    }
    return 0;
}
 
