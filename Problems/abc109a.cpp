#include <iostream>
using namespace std;

int isOdd(int a) { return !(a % 2) ? 1 : 0; }

int main() {
    int a, b;
    cin >> a >> b;
    if (isOdd(a) || isOdd(b)) cout << "No" << endl;
    else cout << "Yes" << endl;
    return(0);
}
