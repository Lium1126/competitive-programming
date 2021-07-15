#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    while (1) {
        if (c % a == 0 && c % b == 0) {
            cout << c << endl;
            break;
        }
        c++;
    }
    return(0);
}
