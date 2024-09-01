#include "Vector.h"
#include "Point.h"
#include <bits/stdc++.h>
using namespace std;


void Vector::print(){
    cout<<"Vector("<<i<<","<<j<<")"<<endl;
}
double Vector::norm() {
    return pow(i,2)+pow(j,2);
}
Vector :: Vector() {
    i=0;
    j=0;
}

Vector :: Vector(double i,double j) {
    this->i=i;
    this->j=j;
}

Vector :: ~Vector () {
    
}

Vector:: operator Point() const{
    Point p(i,j);
    return p;
}
