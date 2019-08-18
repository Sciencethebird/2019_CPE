//
//  main.cpp
//  UVA_1_Star
//
//  Created by Sciencethebird on 2019/7/12.
//  Copyright © 2019 Sciencethebird. All rights reserved.
//

//24921:Guard the Land

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

int main(int argc, const char * argv[]) {
    int nights = 0;
    cin >> nights;
    vector<int> temp(4, 0);
    int rows = nights*2;
    vector<vector<int> > pos(rows, temp);
    
    for(int i = 0; i<rows; i++){
        for(int j = 0; j< 4; j++){
            cin >> pos[i][j];
        }
    }

 
    for(int i = 0; i< rows; i+=2){
        vector<int> t(100, 0);
        vector<vector<int> > map(100, t);
        for(int k = pos[i][1]; k< pos[i][3]; k++){
            for(int l = pos[i][0]; l < pos[i][2]; l++){
                map[k][l] += 1;
            }
        }
        for(int k = pos[i+1][1]; k< pos[i+1][3]; k++){
            for(int l = pos[i+1][0]; l < pos[i+1][2]; l++){
                map[k][l] += 1;
            }
        }
        int w_count = 0, s_count  = 0;
        
        for(int k = 0; k<100; k++){
            for(int j = 0; j< 100; j++){
                if(map[k][j] == 1) w_count++;
                if(map[k][j] == 2) s_count++;
                
            }
            
        }
        cout << "Night " << (i/2)+1<< ": " << s_count << " " << w_count
        <<" "<<10000 - (s_count+w_count)<<endl;
    }
    return 0;
}

