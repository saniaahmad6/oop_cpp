#include <bits/stdc++.h>

using namespace std;
class Clock
{
    private:
        int hour; 
        int minute; 
        int second; 
        string meridian; 
    public:
    //Set the clock to the specified time
    void setClock (int h, int m, int s, string mer)
    {
        hour=h;
        minute=m;
        second=s;
        meridian=mer;
    }

    //Display the time in standard notation
    void displayStandard()
    {
        cout<<"Standard Time is: "<<this->hour<<":"<<this->minute<<":"<<this->second<<" "<<meridian<<endl;
    }

    //Display the time in military notation
    void displayMilitary()
    {
        
        if (meridian=="PM" || meridian=="pm"){
            if (hour==12){
                cout<<"Military Time is: "<<this->hour<<":"<<this->minute<<":"<<this->second<<endl;
            }
            else cout<<"Military Time is: "<<this->hour+12<<":"<<this->minute<<":"<<this->second<<endl;
        }
        else {
            if (hour==12){
                cout<<"Military Time is: "<<this->hour-12<<":"<<this->minute<<":"<<this->second<<endl;
            }
            else cout<<"Military Time is: "<<this->hour<<":"<<this->minute<<":"<<this->second<<endl;
        }
    }
};

int main(){

    Clock *ptr=new Clock();
    int hour; 
    int minute; 
    int second; 
    string meridian; 
    cout<<"Enter hour, minutes, seconds and meridian: ";
    cin>>hour>>minute>>second>>meridian;
    ptr->setClock(hour,minute,second,meridian);
    ptr->displayStandard();
    ptr->displayMilitary();
    return 0;
}