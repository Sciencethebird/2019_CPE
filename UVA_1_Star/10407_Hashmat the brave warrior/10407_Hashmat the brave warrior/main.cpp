//
//  main.cpp
//  10407_Hashmat the brave warrior
//
//  Created by Sciencethebird on 2019/7/8.
//  Copyright © 2019 Sciencethebird. All rights reserved.
//
#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
    long a, b;
    /*
    while (std::cin >> a >> b) {
        if(a>=b) cout << a-b << endl;
        if(a<b) cout << b-a << endl;
    }*/
    while (std::cin >> a >> b) {
        cout << labs(a-b)<< endl;
    }
    return 0;
}

