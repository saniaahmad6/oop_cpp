#include <iostream>

using namespace std;

class Line {
    private:
        double length;
    public:
        void setLength( double len );
        double getLength();
        //constructors
        Line();
        Line(double);
        Line (const Line &line);
        //destructors
        ~Line();
        
}; 

Line::Line () : Line{0} {
    cout<<"Delegating 0 Constructor"<<endl;
}
Line::Line(double len) : length(len){
    cout<<"Delegated Constructor"<<endl;
}


Line::Line(const Line &line){
    cout << "Copy Constructor" << endl;
    this->length=line.length;
}
void Line::setLength( double len ) {
    length = len;
}
double Line::getLength( void ) {
    return length;
}

Line::~Line(){
    cout << "Destructor: " << this->length<< endl;
}

int main() {
    //getters and setters
    Line line1;
    cout<<"Line 1 has length: "<<line1.getLength()<<endl;
    line1.setLength(6.0);
    cout<<"Line 1 has length: "<<line1.getLength()<<endl;

    //parameterized constructor
    Line line2(6.2);
    cout<<"Line 2 has length: "<<line2.getLength()<<endl;

    //copy constructor
    // even if we don't specify a copy constructor, copy is possible
    Line copied(line2);
    cout << "Length of copied : " << copied.getLength() <<endl;

    return 0;
}