#pragma once
#include "Point.h"
#include "Element.h"
#include <bits/stdc++.h>
using namespace std;

class Point;
class Vector : public Element{
    double i;
    double j;

    public: 
        Vector();
        Vector(double i,double j);
        ~Vector ();
        operator Point() const;
        virtual void print() override;
        virtual double norm() override;
};

