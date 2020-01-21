//  22801:Doom's Day Algorithm

#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    int cases;
    cin >> cases;
    int md[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string dn[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    for(int i = 0; i < cases ; i++){
        int m , d;
        cin >> m >> d;
        int days = d;
        for(int j = 0; j< m-1; j++)
            days += md[j];
        
        //cout << days << endl;
        days %= 7;
        days += 5;
        days %= 7;
        cout << dn[days] << endl;
    }
    return 0;
    
}
