#include <bits/stdc++.h>


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
    // setCountQuandrant(&ans);
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




int main(){

    Point::printQuad();
    Point p1(1,1);
    Point p2(2,2);
    Point::printQuad();
    Point p3(-1,-1);
    Point::printQuad();
    Point p4=p1.midPoint(p2);
    Point p5(p3);
    Point::printQuad();
    cout<<"P1 and P2 distance is: " << p1.distFrom(p2)<<endl;

    char grid[100][100];
    int noOfPoints=10;
    // vector <Point> inpPoints(noOfPoints);
    // map <pair<int,int>,int> mapOfPoints;
    // for (int i=0;i<noOfPoints;i++){
    //     int x=abs(rand())%100;
    //     int y=abs(rand())%100;
    //     Point temp(x,y);
    //     mapOfPoints[{x,y}]++;
    //     inpPoints.push_back(temp);
    // }
    // for (int i=0;i<100;i++){
    //     for (int j=0;j<100;j++){
    //         if (mapOfPoints.find({i,j})!=mapOfPoints.end()){
    //             grid[i][j]='0';
    //         }
    //         else{
    //             grid[i][j]='*';
    //         }
    //         cout<<grid[i][j];
    //     }
    //     cout<<endl;
    // }
    return 0;
}

