#pragma once
#include "Point.h"
#include <bits/stdc++.h>
using namespace std;

class Point;

class Location : public Point {
    string address;
    public:

    Location(double x,double y,string s);
    Location(double x,double y);
    Location();
    ~Location();
    Location(const Location &L);
    double distFrom(Location &l);
};



    
   
