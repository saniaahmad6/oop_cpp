#include <iostream>

using namespace std;

class A {
    int x=0;
    public:
    int getx() { return x;}
    A () {
        cout<<"base"<<endl;
    }
    virtual ~A () {
        cout<<"base"<<endl;
    }
};

class B: public A {
    public:
    B() {
        cout<<"derived"<<endl;
    }
    ~B () {
        cout<<"derived"<<endl;
    }

    void operator=(const A & src) {

    }
};


int main() {
    A * ptr=new B();
    delete ptr;

    // virtual base - reverse order called
    // no virtual base - only base called
    return 0;
}