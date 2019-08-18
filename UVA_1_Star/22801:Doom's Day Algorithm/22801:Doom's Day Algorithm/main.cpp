//
//  main.cpp
//  22801:Doom's Day Algorithm
//
//  Created by Sciencethebird on 2019/7/11.
//  Copyright © 2019 Sciencethebird. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
int main(int argc, const char * argv[]) {
    int month_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string dn[7] ={ "Monday",
                    "Tuesday",
        "Wednesday",
        "Thursday",
        "Friday",
        "Saturday",
        "Sunday"
    };
    int start_date = 4;
    int case_num = 0;
    cin >> case_num;
    for(int i = 0; i < case_num; i++){
        int m, d;
        int days = 0;
        cin >> m >> d;
        for(int j = 0; j<m-1; j++){
            days += month_days[j];
        }
        days+=d;
        
        int date = (days%7+start_date)%7;
        cout << dn[date] << endl;
    }
    return 0;
}
