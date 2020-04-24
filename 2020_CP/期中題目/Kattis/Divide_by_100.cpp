// Divide by 100
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
typedef long long ll;
using namespace std;


int main(int argc, const char * argv[]) {
    
    string in, div;
    cin >> in >> div;
    int len = in.size(), zeros = div.length()-1;
    int diff = len-zeros;
    if(diff<=0){
        diff*=-1;
        cout << "0.";
        for(int i = 0; i<diff; i++){
            cout <<0;
        }cout << in << endl;
    }else{
        cout <<in.substr(0, len-zeros);
        string ll =in.substr(len-zeros);
        int idx = ll.size()-1;
        while(ll.back() == '0'){
            ll.pop_back();
        }
        if(ll.size()){
            cout<<"."<< ll<< endl;
        }else{
            cout << endl;
        }
                
    }
    return 0;
}


