//
//  main.cpp
//  UVA_2_Star
//
//  Created by Sciencethebird on 2019/7/11.
//  Copyright © 2019 Sciencethebird. All rights reserved.

//  10505: Center of Masses
/*
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <cmath>
using namespace std;

bool rule(const vector<int>& v1, const vector<int>& v2){
    return v1[1]<=v2[1];
}

int main(int argc, const char * argv[]) {
    int num_points = 0;
    while(1){
        cin >> num_points;
        if(num_points < 3) break;
        vector<double> temp (3, 0);
        vector<vector <double> > points(num_points, temp);
        double x_avg = 0, y_avg = 0;
        for(int i = 0; i < num_points; i++){
            for(int j = 0; j<2; j++){
                cin >> points[i][j];
            }
        }
        int start_x = points[0][0];
        int start_y = points[0][1];
     
        for(int i = 1; i < num_points; i++){
            
            if(points[i][0]-start_x){
                double temp= double(points[i][1]-start_y)/double(points[i][0]-start_x);
                points[i][2] =atan(temp);
            }else{
                points[i][2] = 0.5*3.1415;
            }
            
        }
        //std::sort(points.begin(), points.end(), rule);
        for(int i = 0; i < num_points; i++){
            for(int j = 0; j<3; j++){
                cout << points[i][j] << " ";
            }
            cout << endl;
        }
        //printf("%.3f %.3f", x_avg/num_points, y_avg/num_points);
        
    }
    return 0;
}
*/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
/////////////////////////////////////
struct point{
    double x, y;
    point(double a, double b){
        x = a;
        y = b;
    }
    double Distance(point t){
        return sqrt((x-t.x)*(x-t.x) + (y-t.y)*(y-t.y));
    }
};
vector<point> p;
vector<int> CH; //存放凸包顶点序号   模拟栈
int testCase, top, cc=0, nodeNum;
/////////////////////////////////////
void Input(){
    p.clear();
    CH.clear();
    CH.resize(nodeNum+5);
    double xx, yy;
    for(int i=0; i<nodeNum; i++){
        cin >> xx >> yy;
        p.push_back(point(xx, yy));
    }
}

ostream& operator << (ostream& os, point &p){
    os <<'('<< p.x <<", "<< p.y <<')';
    return os;
}

bool cmp(point a, point b){
    if(a.y == b.y)  return a.x < b.x;
    return a.y < b.y;
}

bool turnRight(point px1, point px2, point pp){
    const double eps = 1e-20;
    
    if((px2.x - px1.x)*(pp.y - px2.y) - (pp.x - px2.x)*(px2.y - px1.y) <= eps) return true;
    return false;
}
void ComputeCH(){
    for(int i = 0; i< p.size(); i++){
        cout << p[i].x << " " << p[i].y << endl;
    } cout << endl;
    sort(p.begin(), p.end(), cmp);
    for(int i = 0; i< p.size(); i++){
        cout << p[i].x << " " << p[i].y << endl;
    } cout << endl;
    CH[0] = 0;
    CH[1] = 1;
    
    top = 1;
    //从起点0到到排序最后点作凸包右链  过程1
    for(int i=2; i<nodeNum; i++){
        while( top && turnRight(p[CH[top-1]], p[CH[top]], p[i]) )
        {
            top--;
            //cout << "top: " << top <<" "<< i << endl;
        }
        cout << "top: " << top <<" "<< i << endl;
        CH[++top] = i;
        
    }
    cout << "step1" <<endl;
    for(int i = 0; i< CH.size(); i++){
        cout << CH[i] <<" "<<p[CH[i]].x<<" "<<p[CH[i]].y<<" "<< endl;;
    }
    int len = top;
    //从排序最高点到到起点0fab反向作凸包右链  过程2
    CH[++top] = nodeNum-2;
    for(int i=nodeNum-3; i>=0; i--){
        //top!=len, 不考虑已在过程1生成凸包上的点
        while( top!=len && turnRight(p[CH[top-1]], p[CH[top]], p[i]) )
        {
            top--;
        }
        CH[++top] = i;
    }
    cout << "step2"<<endl;
    for(int i = 0; i< CH.size(); i++){
        cout << CH[i] <<" "<<p[CH[i]].x<<" "<<p[CH[i]].y<<" "<< endl;;
    }
}

/*计算凸多边形重心模板  该模板另外在求解的过程中，不
 需要考虑点的输入顺序是顺时针还是逆时针，相除后就抵消了。
 */
double Area(point p0, point p1, point p2){
    double area = 0;
    area =  p0.x * p1.y + p1.x * p2.y + p2.x * p0.y - p1.x * p0.y - p2.x * p1.y - p0.x * p2.y;
    return area / 2 ;
}
void ComputeGC(){
    int sPos = 0;
    double sum_x , sum_y , sum_area , area;
    sum_x = sum_y = sum_area = area = 0;
    //一定得按照序进行套用，我从最左下点开始,逆时针扫整个凸包
    for(int i=2; i<top ; i++){
        cout << p[CH[sPos]]<<" "<<p[CH[sPos+1]]<<" "<<p[CH[i]]<<endl;
        area = Area(p[CH[sPos]],p[CH[sPos+1]],p[CH[i]]) ;
        sum_area += area ;
        sum_x += (p[CH[sPos]].x + p[CH[sPos+1]].x + p[CH[i]].x) * area ;
        sum_y += (p[CH[sPos]].y + p[CH[sPos+1]].y + p[CH[i]].y) * area ;
        p[CH[sPos+1]] = p[CH[i]] ;
    }
    printf ("%.3lf %.3lf\n", sum_x/sum_area/3, sum_y/sum_area/3);
}

///////////////////////////////////////////////////////
int main(){
    while(cin >> nodeNum && nodeNum >= 3)
    {
        Input();
        ComputeCH(); //计算凸包
        ComputeGC();  //计算凸多边形重心并输出
    }
    return 0;
}
