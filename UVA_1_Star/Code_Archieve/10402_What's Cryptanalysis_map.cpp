//
//  main.cpp
//  UVA_1_Star
//
//  Created by Sciencethebird on 2019/7/17.
//  Copyright © 2019 Sciencethebird. All rights reserved.
//

// 10402:What's Cryptanalysis?

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    map<char, int> counts;
    map<char, int>::iterator iter, l;
    
    int lines = 0;
    cin>> lines;
    
    string input = "";
    cin.ignore();
    
    for(int i = 0; i<lines; i++){
        string buffer;
        getline(cin, buffer);
        input +=buffer;
    }
    //cout << input << endl;
    size_t len = input.length();
    for(int i = 0; i< len; i++){
        input[i] = toupper(input[i]);
    }
    //cout << input << endl;
    for(int i = 0; i< len; i++){
        if(input[i] - 'A' > 26 ||input[i] - 'A' < 0 ) continue;
        iter = counts.find(input[i]);
        if(iter == counts.end()){
            counts.insert(pair<char, int>(input[i], 1));
        }
        else {
            counts[input[i]] ++;
        }
    }

 
    vector<int> test = {5,2,7,5,8,9};
    std::sort(test.begin(), test.end());
 
    
    // Defining a lambda function to compare two pairs. It will compare two pairs using second field
    std::function < bool(pair<char, int>, pair<char, int> ) > compFunctor =
    [](std::pair<char, int> elem1 ,std::pair<char, int> elem2)
    {
        if(elem1.second == elem2.second){
            return (elem1.first < elem2.first);
        }else{
            return (elem1.second > elem2.second);
        }
    };

    
    std::set<std::pair<char, int>, std::function < bool(pair<char, int>, pair<char, int> ) > > setOfWords(
                                                                counts.begin(), counts.end(), compFunctor);
    
    for (std::pair<char, int> element : setOfWords)
        std::cout << element.first << " " << element.second << std::endl;
    
    return 0;
}

