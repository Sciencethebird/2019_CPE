//  10503:Show the Sequence

#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

int main(int argc, const char * argv[]) {
    
    string seq;
    int N; // N terms
    
    while(cin >> seq >> N){
    
        vector<long long> ans(N, 0);
        long long idx = seq.size() - 1;
        char op = '+';
        
        while(seq[idx] ==']') idx--;
        
        while(idx>0){
            string num;
            while(seq[idx] != '['){
                num = seq[idx] + num;
                idx--;
            }
            if(op =='+'){
                vector<long long> temp(ans);
                ans[0] = atoi(num.c_str());
                for(int i = 1; i< N; i++)
                    ans[i] = ans[i-1] + temp[i-1];
            }
            if(op =='*'){
                vector<long long> temp(ans);
                ans[0] = atoi(num.c_str()) * temp[0];
                for(int i = 1; i< N; i++)
                    ans[i] = ans[i-1] * temp[i];
            }
            if(idx) op = seq[--idx];
            idx--;
        }
        cout << ans[0];
        for(int i = 1;i<ans.size(); i++) cout << " " << ans[i];
        cout << endl;
    }
    return 0;
}
 
//[22] 3
//[233+[11]] 3
//[2*[1+[2+[1]]]] 5
//[2*[5+[-2]]] 7
