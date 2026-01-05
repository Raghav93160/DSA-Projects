#include <iostream>
using namespace std;

int main() {
    long long bytes;

    cout << "Enter memory in Bytes: ";
    cin >> bytes;

    double bits = bytes * 8;
    double kb = bytes / 1024.0;
    double mb = kb / 1024.0;
    double gb = mb / 1024.0;

    cout << "\nMemory Conversion Results:\n";
    cout << "Bits      : " << bits << endl;
    cout << "Bytes     : " << bytes << endl;
    cout << "Kilobytes : " << kb << " KB" << endl;
    cout << "Megabytes : " << mb << " MB" << endl;
    cout << "Gigabytes : " << gb << " GB" << endl;

    return 0;
}

