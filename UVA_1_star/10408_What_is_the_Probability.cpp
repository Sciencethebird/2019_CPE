//  10408:What is the Probability

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main(int argc, const char * argv[]) {
    int cases;
    cin >> cases;
    for(int i = 0; i< cases; i++){
        int N, I;
        double p, q = 1;
        cin >> N >> p >> I;
        for(int i = 0; i< N; i++) q *= (1-p);
        double ans = p*( 1/(1-q) );
        for(int i = 1; i<I; i++) ans *=  (1-p);
        cout  << fixed << setprecision(4) <<ans << endl;
    }
    return 0;
}
