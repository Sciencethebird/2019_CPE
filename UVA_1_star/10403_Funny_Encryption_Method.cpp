//  10403:Funny Encryption Method

#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <sstream>
#include <algorithm> // std::sort

using namespace std;


int main(int argc, const char * argv[]) {
    int cases;
    cin >> cases;
    
    string temp;
    for(int i = 0; i<cases;i++){
        int num, a1 = 0, a2 = 0;
        
        cin>> num;
        bitset<32> b1(num);
        temp = b1.to_string();
        
        for(int i = 0; i<temp.size();i++)
            if(temp[i] == '1') a1++;
        
        stringstream ss;
        ss << num;
        ss >> std::hex >> num;
        
        bitset<32> b2(num);
        temp = b2.to_string();
        //cout << b2 << endl;
        for(int i = 0; i<temp.size();i++)
            if(temp[i] == '1') a2++;
        
        cout << a1 << " " << a2 << endl;
    }
    return 0;
}
