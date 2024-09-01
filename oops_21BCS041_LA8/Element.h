#pragma once
#include <iostream>

class Element {
    public: 
    virtual void print()=0;
    virtual double norm()=0;
};