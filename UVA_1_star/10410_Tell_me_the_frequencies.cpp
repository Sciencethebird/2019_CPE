//  10410:Tell me the frequencies

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

bool comp(vector<int> a, vector<int> b){
    return a[1] > b[1];
}

int main(int argc, const char * argv[]) {
    string buffer;
    bool start = false;
    while(getline(cin, buffer)){
        if(start) cout << endl;
        vector<int>temp(2, 0);
        vector< vector<int> > A(256, temp);
        for(int i = 0; i< 256; i++) A[i][0] = i;
        for(int i = 0; i< buffer.size(); i++)
            A[ buffer[i] ][1] ++;
        
        stable_sort(A.begin(), A.end(), comp);
    
        for(int i = 255; i>=0; i--){
            if(A[i][1]) cout << A[i][0] << " " << A[i][1] << endl;
        }
        start = true;
    }
    return 0;
}
