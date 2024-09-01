#include "PointN.h"
#include "Element.h"

#include <bits/stdc++.h>

using namespace std;

PointN::PointN() {
    n=2;
    ptr=new double[2];
    ptr[0]=0;
    ptr[1]=0;
}

PointN::PointN(double arr[],int n){
    this->n=n;
    ptr=new double[n];
    for (int i=0;i<n;i++) {
        ptr[i]=arr[i];
    }
}

PointN::~PointN(){
    delete [] ptr;
}

double PointN::norm() {
    double ans=0;
    for (int i=0;i<n;i++) {
        ans+=ptr[i]*ptr[i];
    }
    return ans;
}
void PointN::print(){
    cout<<"Dimensions: "<<n<<", Norm: "<<norm()<<endl;
}

