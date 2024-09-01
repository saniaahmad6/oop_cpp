#include <bits/stdc++.h>

using namespace std;

class A {
public:
    string name;
    A(string name_) : name(name_) {

    }
    A() : A{"sania"} {

    }

    A operator+( A b) {
        A a(this->name+b.name);
        return a;
    }
    A& operator++() {
        //pre
        string x = (this->name);
        this->name = x+"a";
        return *this;
    }
    friend ostream& operator<<(ostream &out,A a);

    void operator=(A a) {
        this->name=a.name;
    }

    operator int() const {
        return 1;
    }

};

ostream& operator<<(ostream &out,A a) {
    out <<a.name;
    return out;
}
int main () {
    A x("sania"),b("ahmad");
    A res=x+b;
    cout<<res<<endl;
    ++res;
    cout<<res<<endl;
    res=b;
    cout<<res<<endl;
    int a = res;
    cout<<a<<endl;
    return 0;
}