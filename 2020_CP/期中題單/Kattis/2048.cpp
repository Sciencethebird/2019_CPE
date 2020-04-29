// 2048
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
    unsigned t = 0;
    cout << t -1 << endl;
    int m[4][4];
    for(int i = 0; i< 4; i++){
        for(int j = 0; j<4; ++j){
            cin >> m[i][j];
        }
    }
   
    int dir; cin >> dir;
    if(dir == 0){
        for(int i = 0; i< 4; i++){
            deque<int> temp;
            for(int j = 0; j< 4; j++){
                if(m[i][j]) temp.push_back(m[i][j]);
            }
            for(int j = 0; j< (int)temp.size()-1; j++){
               
                if(temp[j]==temp[j+1]){
                    temp[j] *=2;
                    temp.erase(temp.begin()+j+1);
                }
            }
            for(int j = 0; j< 4; j++){
                if(j<temp.size()){
                    m[i][j] =  temp[j];
                }else{
                    m[i][j] =  0;
                }
            }
        }
    }else if (dir ==1){
        for(int i = 0; i< 4; i++){
            deque<int> temp;
            for(int j = 0; j< 4; j++){
                if(m[j][i]) temp.push_back(m[j][i]);
            }
            for(int j = 0; j< (int)temp.size()-1; j++){
                if(temp[j]==temp[j+1]){
                    temp[j] *=2;
                    temp.erase(temp.begin()+j+1);
                 
                }
            }
            for(int j = 0; j< 4; j++){
                if(j<temp.size()){
                    m[j][i] = temp[j];
                }else{
                    m[j][i] = 0;
                }
            }
        }
    }else if(dir ==2){
        for(int i = 0; i< 4; i++){
            deque<int> temp;
            for(int j = 3; j>= 0; j--){
                if(m[i][j]) temp.push_back(m[i][j]);
            }
            for(int j = 0; j< (int)temp.size()-1; j++){
                if(temp[j]==temp[j+1]){
                    temp[j] *=2;
                    temp.erase(temp.begin()+j+1);
                  
                }
            }
            for(int j = 0; j<4; j++){
                if(j<temp.size()){
                    m[i][3-j] =  temp[j];
                }else{
                    m[i][3-j] =  0;
                }
            }
        }
    }else{
       for(int i = 0; i< 4; i++){
            deque<int> temp;
            for(int j = 3; j>=0; j--){
                if(m[j][i]) temp.push_back(m[j][i]);
            }
            for(int j = 0; j< (int)temp.size()-1; j++){
                if(temp[j]==temp[j+1]){
                    temp[j] *=2;
                    temp.erase(temp.begin()+j+1);
                   
                }
            }
            for(int j = 0; j<4; j++){
                if(j<temp.size()){
                    m[3-j][i] = temp[j];
                }else{
                    m[3-j][i] = 0;
                }
            }
        }
    }
   for(int i = 0; i< 4; i++){
       for(int j = 0; j<4; ++j){
           cout << m[i][j] << " ";
       }cout << endl;
   }
    return 0;
}


