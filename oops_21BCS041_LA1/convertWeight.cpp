#include <bits/stdc++.h>

using namespace std;

// 1 kg = 2.2 pounds
int main() {
    double kg, pounds;
    cout << "Enter the weight in kg: ";
    cin >> kg;
    pounds = kg * 2.2;
    cout << kg << " kilograms is " << pounds << " pounds" <<endl;
    cout << "Enter the weight in pounds: ";
    cin >> pounds;
    kg = pounds / 2.2;
    cout << pounds << " pounds is " << kg << " kilograms" << endl;

    return 0;
}