//  10002:Center of Masses

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <stdlib.h>
#include <deque>
#include <math.h>
#include <algorithm>

using namespace std;
struct point{
    point(){}
    point(double a, double b){
        x = a; y = b;
    }
    double x, y;
};
point triangle_cm(point a, point b, point c){
    return point( (a.x+b.x+c.x)/3, (a.y+b.y+c.y)/3 );
}
double area(point a, point b, point c){
    double t =0.5*(a.x*b.y+b.x*c.y+c.x*a.y - a.y*b.x - b.y*c.x - c.y*a.x);
    if(t >=0) return t;
    else return -t;
}
bool comp(point a, point b){
    return a.y >b.y;
}
bool LR(point a, point b, point c){
    double s = (a.y - b.y)/(a.x - b.x);
    if(s*c.x - c.y - (s*a.x - a.y) > 0) return true;
    else return false;
}
int main(int argc, const char * argv[]) {
    
    int a, b, vtx_num;
    vector<point> vertex;
    
    while(cin >> vtx_num){
        if(vtx_num <3) break;
        vertex.clear();
        for(int i = 0 ; i< vtx_num; i++){
            cin  >> a >> b;
            point t(a, b);
            vertex.push_back(t);
        }
        sort(vertex.begin(), vertex.end(), comp);
        deque<point> base;
        double cmx = 0, cmy = 0, cur_area = 0;
        
        base.push_back(vertex[0]);
        base.push_back(vertex[1]);
        base.push_back(vertex[2]);
        for(int i = 3; i<= vtx_num; i++){
            point cm = triangle_cm(base[0], base[1], base[2]);
            double sec = area(base[0], base[1], base[2]);
            cmx = cm.x*sec + cur_area*cmx;
            cmy = cm.y*sec + cur_area*cmy;
            cur_area += sec;
            cmx /= cur_area;
            cmy /= cur_area;
            
            if(i == vtx_num) {
                cout << fixed << setprecision(3)<< cmx <<" "<< cmy << endl;
                break;
            }
            if(LR(base[2], base[1], vertex[i]) == LR(base[2], base[1], base[0])){
                swap(base[1], base[2]);
                base[2] = vertex[i];
            }else{
                base.pop_front();
                base.push_back(vertex[i]);
            }
        }
    }
    return 0;
}
 
