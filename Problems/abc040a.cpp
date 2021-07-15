#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    cout << min(b - 1, a - b) << endl;
    return(0);
}
