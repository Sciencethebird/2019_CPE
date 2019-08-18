//
//  main.cpp
//  UVA_1_Star
//
//  Created by Sciencethebird on 2019/7/17.
//  Copyright © 2019 Sciencethebird. All rights reserved.
//

// 10405:Jolly Jumpers

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <bitset>
#include <algorithm>
#include <sstream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    string input = "";
    int input_len = 0;
    while(cin >> input_len){
        vector<int> numbers(input_len, 0);
        for(int i = 0; i< input_len; i++)
            cin >> numbers[i];
        vector<int> diff;
        for(int i = 0; i<input_len-1; i++){
            diff.push_back(labs(numbers[i]-numbers[i+1]));
        }
        
        bool jolly = 1;
     
       
        //cout << jolly << endl;
        std::sort(diff.begin(), diff.end());
        for(int i = 0; i<input_len-2; i++){
            if(diff[i+1] - diff[i]>1) {jolly = 0;}
        }
        if(input_len> 1){
            if(diff.back() == input_len-1){
                if(jolly) {cout << "Jolly" << endl;}
                else{ cout << "Not Jolly" << endl;}
            }
            else {cout << "Not jolly" << endl;}
        }else{
            cout << "Jolly" << endl;
        }
        
    }
    return 0;
}
/*
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main(){
    int n;
    int jolly[3005];
    bool jollyp = 1;
    while( scanf( "%d", &n ) != EOF ){
        bool jump[3005] = {0};
        jollyp = 1;
        for( int i = 0 ; i < n ; i++ )
            scanf( "%d", &jolly[i] );
        for( int i = 1 ; i < n ; i++ ){
            if( abs(jolly[i] - jolly[i-1]) >= n ||
               abs(jolly[i] - jolly[i-1]) <= 0 ||
               jump[abs(jolly[i] - jolly[i-1])] ){
                
               jollyp = 0;
               break;
            }
            jump[abs(jolly[i] - jolly[i-1])] = 1;
        }
        if( jollyp )
            printf( "Jolly\n" );
        else
            printf( "Not jolly\n" );
    }
    return 0;
}
*/
//6 1 -4 0 2 1 2
//Not jolly
//6 1 -4 0 2 1 4
//Jolly


