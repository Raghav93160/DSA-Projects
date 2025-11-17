// file: looper_for.cpp
#include <iostream>
using namespace std;

string gradeFromMarks(int marks) {
    if (marks < 0 || marks > 100) return "Invalid";
    if (marks >= 90) return "A+";
    if (marks >= 80) return "A";
    if (marks >= 70) return "B";
    if (marks >= 60) return "C";
    if (marks >= 50) return "D";
    return "F";
}

int main() {
    int n;
    cout << "How many students? ";
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int marks;
        cout << "Student " << i << " marks: ";
        cin >> marks;
        cout << "Grade: " << gradeFromMarks(marks) << "\n";
    }
    return 0;
}

