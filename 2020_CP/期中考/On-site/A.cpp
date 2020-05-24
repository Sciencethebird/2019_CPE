// A

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <math.h>
#include <deque>
#include <sstream>
#include <queue>
#include <iomanip>
#include <bitset>
typedef long long ll;
using namespace std;
const int inf = 1<<30;

void my_sort(vector<int> a, int k){
    int count = 0;
    for(int i = 0; i< a.size(); i++){
        for(int j = i+1; j<a.size(); j++){
            if(a[i] >a[j]) {
                count+=((i+j)%k);
                swap(a[i], a[j]);
            }
        }
    }
    cout << count << endl;
    for(auto i:a){
        cout << i << " ";
    }cout << endl;
}
int main(int argc, const char * argv[]) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n, 0), b(n, 0);
    
    for(auto &i:a){
        cin >> i;
    }
    for(auto &i:b){
        cin >> i;
    }
    my_sort(b, k);
}
