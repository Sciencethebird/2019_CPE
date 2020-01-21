//  10407:Hashmat the brave warrior

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    long long a, b, diff;
      while(cin >> a >> b){
          diff = a-b;
          if(diff >= 0 ) cout << diff<< endl;
          else cout << -diff << endl;
      }
      return 0;
    
}
