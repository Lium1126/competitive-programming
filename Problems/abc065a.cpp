#include <iostream>
using namespace std;

int main() {
    int a, b, x;
    cin >> x >> a >> b;
    if (a >= b) cout << "delicious" << endl;
    else if (b - a <= x) cout << "safe" << endl;
    else cout << "dangerous" << endl;
    return(0);
}
