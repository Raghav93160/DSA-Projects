// file: circle_basic.cpp
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double r;
    cout << "Enter radius: ";
    if (!(cin >> r) || r < 0) {
        cout << "Invalid radius\n";
        return 0;
    }

    double area = M_PI * r * r;             // pr^2
    double circumference = 2 * M_PI * r;    // 2pr

    cout << "Area: " << area << "\n";
    cout << "Circumference: " << circumference << "\n";
    return 0;
}

