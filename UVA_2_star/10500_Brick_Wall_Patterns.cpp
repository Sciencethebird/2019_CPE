//  10500:Brick Wall Patterns

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main(int argc, const char * argv[]) {
    int num;
    long long ans[50] = {1, 2};
    for(int i = 2; i< 50; i++){
        ans[i] = ans[i-1] + ans[i-2];
    }
    while(cin>> num){
        if(num == 0) break;
        cout << ans[num-1] << endl;
    }
    return 0;
}
 
