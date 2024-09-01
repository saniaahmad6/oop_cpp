#include "Location.h"
#include "Point.h"
#include <bits/stdc++.h>
using namespace std;
Location::Location(double x,double y,string s) : Point(x,y){
    address = s;
    cout<<"Derived Class Constructor  with address"<<endl;
}
Location::Location(double x,double y) : Point(x,y){
    cout<<"Derived Class Paremeterized Constructor"<<endl;
}
Location::Location() : Point(){
    cout<<"Derived Class Default Constructor"<<endl;
}
Location::Location::~Location(){
    cout<<"Derived destructor"<<endl;
}

Location::Location(const Location &L) : Point(L){
    cout<<"Derived copy constructor"<<endl;
}
double Location::distFrom(Location &l){
        auto p1=l.getCoord();
        double x1=p1.first;
        double y1=p1.second;
        auto p2=this->getCoord();
        double x2=p2.first;        
        double y2=p2.second;  
        double angle=acos((x1*x2+y1*y2)/(sqrt(x1*x1+y1*y1)*sqrt(x2*x2+y2*y2)));
        double distance=angle * 6371;
        return distance;
}