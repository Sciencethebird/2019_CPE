// Aries_int_hashing_compact
 
#include <iostream>

#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <deque>
#include <sstream>
#include <queue>
#include <iomanip>
#include <bitset>
#include <unordered_map>

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <math.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int inf = 1<<30;

ull read_mask[16];//{15, 15<<4, 15 << 8, 15 << 12, 15 << 16, 15 >> 20, 15 << 24, 15 << 24,};
ull erase_mask[16];//{15, 15<<4, 15 << 8, 15 << 12, 15 << 16, 15 >> 20, 15 << 24, 15 << 24,};
ull goal = 0x0123456789ABCDEF;
ull fp =   0xFFFFFFFFFFFFFFFF;
int pivot[9] = {0, 1 ,2, 4, 5, 6, 8, 9, 10};

ull get_value(ull &m, int pos){
    //cout << read_mask[pos] << endl << m << endl;
    return (m&read_mask[pos])>> (15-pos)*4;
}
void map_assign(ull&m, int pos, ull value){
    m = m&erase_mask[pos];
    //cout << (value << (60-pos*4))<<endl;
    m = m | value << (15-pos)*4 ;
}

ull CW(ull m, int p ){
    ull t1 = get_value(m, p), t2 = get_value(m, p+1), t3 = get_value(m, p+4), t4 = get_value(m, p+5);
    map_assign(m, p, t3);
    map_assign(m, p+1, t1);
    map_assign(m, p+4, t4);
    map_assign(m, p+5, t2);
    return m;
}
ull CCW(ull m, int p ){
    ull t1 = get_value(m, p), t2 = get_value(m, p+1), t3 = get_value(m, p+4), t4 = get_value(m, p+5);
    map_assign(m, p, t2);
    map_assign(m, p+1, t4);
    map_assign(m, p+4, t1);
    map_assign(m, p+5, t3);
    return m;
}
void print_map(ull m){
    stringstream ss;
    ss << std::setfill ('0') << std::setw(16) << std::hex << m;
    string out = ss.str();
    cout << endl;
    for(int i = 0; i<16; i++){
        if(i&&i%4==0) cout << endl;
        cout << out[i] << " ";
    }cout << endl;
}

void bi_directional_bfs(ull &m){
    
    queue<ull> q[2];
    unordered_map<ull, bool> vst[2];
    q[0].push(m); q[1].push(goal);
    vst[0][m] = 1; vst[1][goal] = 1;
    bool turn = 1;
    for(int step = 1; step <=10; step++){
        turn = !turn;
        ull q_size = q[turn].size();
        while(q_size--){
            ull now = q[turn].front();
            q[turn].pop();
            
            for(int i = 0; i<9; i++){
                ull next_m;
                if(turn)
                    next_m = CCW(now, pivot[i]);
                else
                    next_m = CW(now, pivot[i]);
                if(!vst[turn].count(next_m)){
                    vst[turn][next_m] = 1;
                    q[turn].push(next_m);
                }
                if(vst[!turn].count(next_m)){
                    printf("%d\n", step);
                    return;
                }
            }
        }
    }
    printf("HARD ARIES\n");
}
   
int main(int argc, const char * argv[]) {
    
    for(int i = 0; i<16; i++){
        read_mask[15-i] = (ull)15 << (i*4);
        erase_mask[15-i] = read_mask[15-i]^fp;
    }
    int cases;
    cin >> cases;
    while(cases--){
        ull m = 0;
        int temp;
        for(int i = 0; i< 16; i++){
            m = m <<4;
            scanf("%d", &temp);
            m+=(temp-1);
        }
        if(m==goal) printf("0\n");
        else bi_directional_bfs(m);
    }
    return 0;
}

/*
4
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16

 
 
 1 3 4 8
 5 2 14 15
 11 6 10 12
 9 7 13 16
 1 4 12 16
 8 9 2 3
 6 5 11 10
 13 14 7 15
 */
/*
1+3+6+10+15
2 3 4
*/

