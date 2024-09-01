#include <iostream>
#include <chrono>
#include <thread>

using namespace std;
class MyClass {
public:
    MyClass() {
        // Simulate a long-running task in the constructor
        cout << "Constructor executing..." << endl;
        this_thread::sleep_for(chrono::seconds(5)); // Sleep for 5 seconds
        cout << "Constructor completed." << endl;
    }
};

int main() {
    cout << "Creating an object..." << endl;
    MyClass myObject; // The constructor will take 5 seconds to complete
    cout << "Object created." << endl;

    return 0;
}
