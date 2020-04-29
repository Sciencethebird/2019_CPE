// Erase Securely
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

typedef long long ll;
using namespace std;

int main(int argc, const char * argv[]) {
    int N;
    string s1, s2;
    bool ok;
    cin>> N;
    cin >> s1 >> s2;
    if(N%2==0){
        if(s1==s2) ok = true;
        else ok = false;
    }else{
        ok = true;
        for(int i = 0; i < s1.size(); ++i){
            if(s1[i] == s2[i]) ok = false;
        }
    }
    if(ok){
        cout << "Deletion succeeded" << endl;
    }else{
        cout << "Deletion failed" << endl;
    }
    return 0;
}

