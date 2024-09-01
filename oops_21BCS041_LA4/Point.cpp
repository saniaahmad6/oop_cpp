#include <bits/stdc++.h>
#define e 0.000000000001


using namespace std;

class Point {
    double _x;
    double _y;
    static int countBL,countTL,countBR,countTR;
    static int count;
    public: 
        
        void setCoords( double x, double y );
        pair <double,double> getCoord(){ return {_x,_y};}
        void printCoords() const;

        double distFrom(Point &p) const;
        Point midPoint(Point &p) const;

        Point(); // This is the DEFAULT constructor
        Point(double x, double y); // This is the PARAMETERIZED constructor
        Point(const Point &p); // This is the COPY constructor
        ~Point(); // This is the destructor

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

};


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

void Point::setCoords(const double x, double y ){
    delCountFromQuandrant(this);
    _x=x;
    _y=y;
    setCountQuandrant(this);
    
}

void Point::printQuad() {
    cout<<"No. of  Points in I quad: "<<countTR<<endl;
    cout<<"No. of  Points in II quad: "<<countTL<<endl;
    cout<<"No. of  Points in III quad: "<<countBL<<endl;
    cout<<"No. of  Points in IV quad: "<<countBR<<endl;
    cout<<"No. of  Points: "<<count<<endl;
}

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
    delCountFromQuandrant(&ans); //delete 0,0 logic
    ans._x=(this->_x + p._x)/2;
    ans._y=(this->_y + p._y)/2;
    setCountQuandrant(&ans);
    return (ans);
}


Point::Point() {
    _x=0;
    _y=0;
    count++;
    setCountQuandrant(this);
    cout<<"Non-parameterized Constructor"<<endl;

}
Point::Point(double x, double y ) : _x(x),_y(y){
    setCountQuandrant(this);
    cout<<"Parameterized Constructor"<<endl;
    count++;
}

Point::~Point(){
    cout<<"Destructor"<<endl;
    count--;
    delCountFromQuandrant(this);
}

Point:: Point(const Point &p) {
    _x=p._x;
    _y=p._y;
    setCountQuandrant(this);
    count++;
    cout<<"Copy Constructor"<<endl;
}



Point Point::operator + (const Point & p) const{
    Point P;
    P._x=_x+p._x;
    P._y=_y+p._y;
    setCountQuandrant(&P);
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
    setCountQuandrant(&P);
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
    setCountQuandrant(&q);
    return q;
}

int main(){
    
    Point p1(1,1);
    Point p2(2,2);
    Point p3(-1,-1);
    Point p4=p1.midPoint(p2);
    Point p5(p3);
    Point p6=p3;
    Point::printQuad();
    
    //arithmetic
    Point p7=p1+p2+p4;
    p7.printCoords();
    Point::printQuad();

    //relational
    cout<<(p1<p2)<<endl;
    cout<<(p3>p4)<<endl;
    cout<<(p1==p4)<<endl;


    // linear combination
    Point res=p2.linear_combine(p1,0.2);
    res.printCoords();
    Point::printQuad();
    
    
    return 0;
}

