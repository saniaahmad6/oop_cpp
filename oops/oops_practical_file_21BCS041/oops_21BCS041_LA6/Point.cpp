#include "Point.h"
#include "Vector.h"
#include <bits/stdc++.h>
#include <chrono>
#define e 0.000000000001


using namespace std;

void Point:: printCoords() const{
    cout<<"The point is "<<_x<<","<<_y<<endl;
}
double Point::distFrom(Point &p) const{
    double x=this->_x - p._x;
    double y=this->_y - p._y;
    double sum=sqrt(pow(x,2)+pow(y,2));
    return sum;
}
Point Point::midPoint(Point &p) const {
    Point ans; 
    ans._x=(this->_x + p._x)/2;
    ans._y=(this->_y + p._y)/2;
    return (ans);
}


Point::Point() {
    _x=0;
    _y=0;

    // cout<<"Non-parameterized Constructor"<<endl;

}
Point::Point(double x, double y ) : _x(x),_y(y){
    // cout<<"Parameterized Constructor"<<endl;

}
Point::Point (double arr[2]){
    _x=arr[0];
    _y=arr[1];
}

Point::~Point(){
    // cout<<"Destructor"<<endl;

}

Point:: Point(const Point &p) {
    _x=p._x;
    _y=p._y;
    // cout<<"Copy Constructor"<<endl;
}

Point:: operator double *() const {
    double * arr= new double[2];
    arr[0]=_x;
    arr[1]=_y;
    return arr;
}

int Point::count=0;
int Point::countTL=0;
int Point::countTR=0;
int Point::countBR=0;
int Point::countBL=0;


int Point::getcount () {
    return count;
}
int Point::checkQuad(Point *p) {
    if (p->_x>0 &&p->_y>0) {
        return 1;
    }else if (p-> _x>0 && p->_y <0){
        return 4;
    }
    else if (p-> _x<0 && p->_y>0){
        return 2;
    }
    else if (p-> _x<0 && p->_y <0){
        return 3;
    } 
    return 0;
}

void Point::setCountQuandrant(Point *p){
    int quad=checkQuad(p);
    if (quad==1) countTR++;
    if (quad==2) countTL++;
    if (quad==3) countBL++;
    if (quad==4) countBR++;
}

void Point::delCountFromQuandrant(Point *p){
    int quad=checkQuad(p);
    if (quad==1) countTR--;
    if (quad==2) countTL--;
    if (quad==3) countBL--;
    if (quad==4) countBR--;
}


void Point::printQuad() {
    cout<<"No. of  Points in I quad: "<<countTR<<endl;
    cout<<"No. of  Points in II quad: "<<countTL<<endl;
    cout<<"No. of  Points in III quad: "<<countBL<<endl;
    cout<<"No. of  Points in IV quad: "<<countBR<<endl;
    cout<<"No. of  Points: "<<count<<endl;
}
Point Point::operator + (const Point & p) const{
    Point P;
    P._x=_x+p._x;
    P._y=_y+p._y;
    
    return P;
}

bool Point::operator < (const Point & p) const{
    
    double dis1=pow(p._x,2)+pow(p._y,2);
    double dis2=pow(_x,2)+pow(_y,2);
    return dis1>dis2;
}
bool Point::operator > (const Point & p) const{
    
    double dis1=pow(p._x,2)+pow(p._y,2);
    double dis2=pow(_x,2)+pow(_y,2);
    return dis1<dis2;
}
Point Point::operator * (double s) const{
    Point P;
    P._x=_x*s;
    P._y=_y*s;

    return P;
}

bool Point::operator == (const Point & p) const{
    
    double dis1=pow(p._x,2)+pow(p._y,2);
    double dis2=pow(_x,2)+pow(_y,2);
    return abs(dis1-dis2)<e;
}

Point Point::linear_combine(const Point & p,double s){
    Point q;
    q=(*(this))*s+ p*(1-s);
    return q;
}

double Point::I2Norm(){
    double dis=pow(_x,2)+pow(_y,2);
    dis=sqrt(dis);
    return dis;
}
double & Point::operator[](int ind){
    if (ind<0 || ind>1) cout<<"err"<<endl;
    if (ind==0) return _x;
    else if (ind==1) return _y;
    else throw 1;
}

ostream& operator<<(ostream &out, Point &p){
    out<<"Point ("<<p._x<<","<<p._y<<"), Norm = "<<p.I2Norm()<<endl;
    return out;
}

void Point::insertionSort(vector <Point> &arr){
    auto start = chrono::high_resolution_clock::now();
    int n=arr.size();
    for (int i=1;i<n;i++){
        
        Point key=arr[i];
        int j=i-1;
        while (arr[j]>key && j>=0){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
        
    }
    auto stop = chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    cout << duration.count()<<" microseconds" << endl;
}

void insertionSort(vector <int> &arr){
    auto start = chrono::high_resolution_clock::now();
    int n=arr.size();
    for (int i=1;i<n;i++){
        
        int key=arr[i];
        int j=i-1;
        while (arr[j]>key && j>=0){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
        
    }
    auto stop = chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    cout << duration.count()<<" microseconds" << endl;
}


Point::operator Vector() const{
    Vector v(_x,_y);
    return v;
}

