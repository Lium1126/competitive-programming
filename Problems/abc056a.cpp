#include <iostream>
using namespace std;

int main() {
    char a, b;
    bool x, y; x = y = false;
    cin >> a >> b;
    if (a == 'H') x = true; if (b == 'H') y = true;
    if (!(x ^ y)) cout << 'H' << endl;
    else cout << 'D' << endl;
    return(0);
}
