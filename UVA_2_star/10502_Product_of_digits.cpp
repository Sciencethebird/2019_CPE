//  10502:Product of digits

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int cases;
    cin >> cases;
    
    for(int k = 0; k< cases; k++){
        int num;
        cin >> num;
        if(num < 10) {
            cout << num << endl;
            continue;
        }
        vector<int> ans;
        bool exist = true;
        while(num != 1){
            for(int i =9; i>=1; i--){
                if(i == 1){
                    cout << -1 << endl;
                    num = 1;
                    exist = false;
                    break;
                }
                if(num % i == 0){
                    ans.push_back(i);
                    num /= i;
                    break;
                }
            }
        }
        if(exist){
            for(int i  = ans.size() - 1; i>=0; i--){
                cout << ans[i];
            }cout << endl;
        }
    }
    return 0;
}
 
