#pragma once
#include <bits/stdc++.h>
#include "Vector.h"
#include "Element.h"


using namespace std;

class Vector;
class Point : public Element{
    double _x;
    double _y;
    static int countBL,countTL,countBR,countTR;
    static int count;
    public: 
        virtual void print() override;
        virtual double norm() override;
        void setCoords( double x, double y );
        pair <double,double> getCoord(){ return {_x,_y};}
        void printCoords() const;

        double distFrom(Point &p) const;
        Point midPoint(Point &p) const;

        Point(); // This is the DEFAULT constructor
        Point(double x, double y); // This is the PARAMETERIZED constructor
        Point(const Point &p); // This is the COPY constructor
        Point(double arr[]);
        virtual ~Point(); // This is the destructor

        static int getcount();
        static int checkQuad(Point *p);
        static void setCountQuandrant(Point *p);
        static void delCountFromQuandrant(Point *p);
        static void printQuad();

        //Operator overloading
        Point operator + (const Point & p) const;
        bool operator < (const Point & p) const;
        bool operator > (const Point & p) const;
        bool operator == (const Point & p) const;
        Point operator * (double s) const;


        Point linear_combine(const Point & p,double s);


        //output stream
        friend ostream& operator<<(ostream &out,Point &p);
       

        double I2Norm();
        double &operator[](int ind);
        static void insertionSort(vector <Point> &arr);

        operator double *() const;

    
};
