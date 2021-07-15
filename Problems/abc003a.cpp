#include <iostream>
using namespace std;

int main() {
    double n;
    cin >> n;

    cout << ((n * (n + 1.0)) / 2.0) * (1.0 / n) * 10000.0 << endl;

    return(0);
}
