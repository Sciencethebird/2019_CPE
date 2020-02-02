//  10414:Bangla Numbers

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stdlib.h>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int space[5] = {2, 1, 2, 2, 2}, case_num = 1;
    string name[5] = {"kuti", "shata", "hajar", "lakh", ""}, num;
    
    while(cin >> num){
        
        int idx = num.size(), space_idx = 4;
        stringstream ss;
        string sec, temp, out;
        
        while(1){
            idx -= space[space_idx];
            if(idx <= 0) {
                idx += space[space_idx];
                sec = num.substr(0, idx);
                if( atoi(sec.c_str()) )
                    ss << " " << name[space_idx] << " " << atoi(sec.c_str());
                break;
            }
            
            sec = num.substr(idx, space[space_idx]);
            if( atoi(sec.c_str()) )
                ss << " " <<name[space_idx] << " " << atoi(sec.c_str());
    
            space_idx ++;
            space_idx %= 4;
        }
        
        ss >> temp;
        out = temp;
        while(ss>>temp) out = temp + " " + out;
        cout << case_num <<". "<<out << endl;
       
        case_num++;
    }
    return 0;
}
 
