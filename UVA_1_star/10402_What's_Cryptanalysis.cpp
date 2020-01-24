//  10402:What's Cryptanalysis

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <algorithm> // std::sort

using namespace std;

void tolwer(string &in){
    for(int i = 0; i < in.length(); i++)
        if(in[i]>='A' && in[i]<='Z')
            in[i] = in[i] - 'A' +'a';
}

// comp swaps a and b (whatever they are) if true
bool comp(const vector<int>  &a, const vector<int> &b){
    return a[1]>b[1];
}

int main(int argc, const char * argv[]) {
    int lines;
    cin >> lines;
    vector<int> pair(2, 0);
    vector< vector<int> > count(26, pair);
    for(int i = 0; i< count.size(); i++)
        count[i][0] = i;
    cin.ignore();
    for(int i = 0; i< lines; i++){
        string buffer;
        getline(cin, buffer);
        tolwer(buffer);
        for(int i = 0; i< buffer.length(); i++){
            int temp = buffer[i] - 'a';
            if(temp >= 0 && temp <=26)
                count[buffer[i] - 'a'][1]++;
        }
    }
    //stable_sort is necessary !!
    stable_sort(count.begin(), count.end(), comp);
    
    for(int i = 0; i< count.size(); i++){
        if(count[i][1])
            cout << (char)(count[i][0] +'A') << " " << count[i][1] << endl;
    }
    return 0;
}
