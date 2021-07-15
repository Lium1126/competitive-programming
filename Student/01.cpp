#include <iostream>
using namespace std;

int main() {
    int x, y, z;
    cin >> x >> y >> z;

    double d = (double)y / (double)x;

    int i = 0;
    while(1) {
        if (((double)i / (double)z ) >= d) {
            cout << i - 1 << endl;
            break;
        }
        i++;
    }

    return 0;
}