#include <iostream>
#include "Point.h"
#include "Location.h"
#include "Vector.h"
#include "Element.h"


using namespace std;
int main(){
    
    Location obj;
    Location obj1(23,45);
    Location obj2(34,56,"Delhi");

    Location p1(1,3,"Mumbai"),p2(3,4,"Pune");
    p1.printCoords();
    p2.printCoords();
    cout<<"Distance between p1 and p2 is: "<< p1.distFrom(p2) <<endl;

    //after overriding - geodesic distance


    vector <Location> inpArr= {Location(28.66992,77.29162,"shahadra mandi eastern"),
        Location(28.68991,77.30672,"GTB CROSSING eastern"),
        Location(28.68991, 77.25796,"kalash nagar pusta eastern"),
        Location(28.64789, 77.29509,"jagatpuri red light eastern"),
        Location(28.65005, 77.31381,"ISBT ANAND VIHAR eastern"),
        Location(28.67069, 77.26678,"Seelampur T-Point eastern"),
        Location(28.7111 ,77.26034,"khajori chowk eastern"),
        Location(28.70129, 77.29146,"loni gol chakkar eastern"),
        Location(28.61812 ,77.32086,"Kondli Bridge eastern"),
        Location(28.63583,77.28713,"nirman vihar eastern")};

    double distance=0;
    for (int i=1;i<inpArr.size();i++) {
        distance+=inpArr[i].distFrom(inpArr[i-1]);
    }
    cout<<"Total distance: "<<distance<<" km"<<endl;



    // virtual function
    Location myobject(34,56,"my Location");
    myobject.print();
    return 0;

}


