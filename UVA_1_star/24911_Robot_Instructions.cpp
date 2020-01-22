//  24911:Robot Instructions

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;

int main(int argc, const char * argv[]) {
    int cases;
    cin >> cases;
    for(int i = 0; i< cases; i++){
        int len;
        cin >> len;
        vector<int> mnt(len, 0);
        int pos = 0;
        string ins;
        cin.ignore();
        for(int j = 0; j < len; j++){
            
            getline(cin, ins);
            //cout << ins << endl;
            if(ins[0] == 'L'){
                mnt[j] = -1;
                pos--;
            }else if(ins[0] == 'R'){
                mnt[j] = 1;
                pos++;
            }else if(ins[0] == 'S'){
                int idx = atoi( ins.substr(8).c_str() );
                mnt[j] = mnt[idx - 1];
                pos += mnt[j];
                
            }
            //cout << pos << endl;
        }
        cout << pos << endl;
    }

    return 0;
}
