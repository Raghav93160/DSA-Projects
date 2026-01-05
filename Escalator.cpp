#include <iostream>
using namespace std;

int main() {
    int choice, steps;

    cout << "ESCALATOR SIMULATION\n";
    cout << "1. Move Up\n";
    cout << "2. Move Down\n";
    cout << "Enter your choice: ";
    cin >> choice;

    cout << "Enter number of steps: ";
    cin >> steps;

    if (choice == 1) {
        cout << "\nEscalator Moving UP:\n";
        for (int i = 1; i <= steps; i++) {
            cout << "Step " << i << " up\n";
        }
    }
    else if (choice == 2) {
        cout << "\nEscalator Moving DOWN:\n";
        for (int i = steps; i >= 1; i--) {
            cout << "Step " << i << " down\n";
        }
    }
    else {
        cout << "Invalid Choice!";
    }

    return 0;
}

