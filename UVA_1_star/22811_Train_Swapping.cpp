//  22811:Train Swapping

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    int cases;
    cin >> cases;
    for(int i = 0; i< cases; i++){
        int len;
        cin >> len;
        vector<int> a(len, 0);
        for(int j = 0; j< len; j++){
            cin >> a[j];
        }
      
        int ans = 0;
        for(int i = 0; i< len; i++){
            for(int j = i+1; j< len; j++){
                if(a[i]>a[j]){
                    swap(a[i], a[j]);
                    ans++;
                }
            }
        }
        
        cout << "Optimal train swapping takes " << ans <<" swaps." << endl;

    }
    return 0;
}
