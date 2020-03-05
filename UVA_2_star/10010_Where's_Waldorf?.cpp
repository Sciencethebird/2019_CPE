//  10010_Where's Waldorf?

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <map>
#include <queue>
using namespace std;
enum dn {U, D, L, R, UR, UL, DR, DL};
int dir[8][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

int m, n;
char words[55][55];


void to_upper(){
    for(int i = 0; i< m; i++){
        for(int j = 0; j< n; j++){
            if(words[i][j] > 'Z'){
                //cout << words[i][j] << endl;
                words[i][j] = words[i][j] - 'a' + 'A';
            }
        }
    }
}
string to_upper(string in){
    //cout << "eeee" << endl;
    for(int i = 0; i< in.size(); i++){
        if(in[i]> 'Z'){
            in[i] = in[i] - 'a' + 'A';
        }
    }
    return in;
}
void search_words(string word){
    int end = word.size() -1;
    
    for(int i = 0; i< m; i++){
        for(int j = 0; j< n; j++){
            
            for(int d = 0; d<8; d++){
                int cur_i = i, cur_j = j, word_idx = 0;
                while(word[word_idx] == words[cur_i][cur_j]){
                    if(word_idx == end){
                        cout << i +1<< " " << j+1 << endl;
                        return;
                    }
                    word_idx++;
                    cur_i = (cur_i+m+dir[d][0])%m;
                    cur_j = (cur_j+n+dir[d][1])%n;
                }
            }
        }
    }
}
int main(int argc, const char * argv[]) {

    int cases;
    cin >> cases;
    while(cases--){
        
        cin >> m >> n;
        for(int i = 0; i< 55; i++)
            for(int j = 0; j< 55; j++)
                words[i][j] = 0;
        for(int i = 0; i< m; i++){
            for(int j = 0; j< n; j++){
                cin >> words[i][j];
            }
        }
        to_upper();
        
        int request;
        string temp;
        cin >> request;
        while(request--){
            cin >> temp;
            search_words(to_upper(temp) );
        }
        if(cases > 0){
            cout << endl;
        }
    }
    return 0;
}
 


