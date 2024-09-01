
#pragma once

#include <bits/stdc++.h>
#include "Element.h"
using namespace std;

class PointN : public Element {
    int n;
    double *ptr;

    public: 
        PointN();
        PointN(double arr[],int n);
        ~PointN();

        virtual void print() override;
        virtual double norm() override;

};

