#include <iostream>
#include "Point.h"
#include "Vector.h"


using namespace std;
int main(){
    
    double arr [2] = {1,2};
    Point p1(arr);
    cout << p1[0] << "," << p1[1]<<endl;
    p1.printCoords();


    double * parr = p1;
    cout << parr[0] << "," << parr[1]<<endl;


    Point p4(1,1);
    Vector v1 = p4;
    return 0;

}