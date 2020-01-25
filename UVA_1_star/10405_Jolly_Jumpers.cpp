//  10405:Jolly Jumpers

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    int len, prev, num;
    while(cin >> len){
        vector<bool> diff(len, false);
        bool jolly = true;
        diff[0] = true;
        cin>> prev;
        for(int i = 1; i< len; i++){
            cin >> num;
            int d = num - prev;
            prev = num;
            if(d < 0) d = -d;
            if(diff[d] == true || d > len - 1)
                jolly = false;
            diff[d] = true;
        }
        if(jolly) cout << "Jolly" << endl;
        else cout << "Not jolly" << endl;
    }
    return 0;
}
