#pragma once
#include "Point.h"
#include <bits/stdc++.h>
using namespace std;

class Point;
class Vector {
    double i;
    double j;

    public: 
        Vector();
        Vector(double i,double j);
        ~Vector ();
        operator Point() const;
};

