//  10406:Vito's family

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    int cases;
    cin >> cases;
    for(int i = 0; i< cases; i++){
        int len;
        cin >> len;
        vector<int> street (len, 0);
        for(int i = 0; i< len; i++)
            cin >> street[i];
        sort(street.begin(), street.end());
        long long dis = 0, mid = street[(len-1)/2], diff;
        for(int i = 0; i < len; i++){
            diff = mid - street[i];
            if(diff > 0) dis+=diff;
            else dis -= diff;
        }
        cout << dis << endl;
    }
    return 0;
}
