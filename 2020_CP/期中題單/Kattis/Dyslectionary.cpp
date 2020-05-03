// Dyslectionary

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
typedef long long ll;
using namespace std;

void process(vector<string> &words, ll max_len){
    sort(words.begin(), words.end());
    
    for(auto i: words){
        string temp(max_len - i.size(), ' ');
        //temp.resize(max_len - i.size(), ' ');
        //temp += string(i.rbegin(), i.rend());
        cout <<setw(max_len)<< string(i.rbegin(), i.rend()) << endl;
    }
    
}
int main(int argc, const char * argv[]) {
    string buffer;
    vector<string> words;
    ll max_len = 0;
    while(getline(cin, buffer)){
        if(buffer == ""){
            process(words, max_len);
            cout << endl;
            words.clear();
            max_len = 0;
            continue;
        }
        if(buffer.size()>max_len){
            max_len = buffer.size();
        }
        reverse(buffer.begin(), buffer.end());
        words.push_back(buffer);
    }
    // This line is important
    process(words, max_len);
    return 0;
}

