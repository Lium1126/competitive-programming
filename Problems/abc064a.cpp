#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if (!((a * 100 + b * 10 + c) % 4)) cout << "YES" << endl;
    else cout << "NO" << endl;
    return(0);
}
