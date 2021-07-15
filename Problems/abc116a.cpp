#include <iostream>
using namespace std;

int main() {
    int a, b, c, Max = 0;
    cin >> a;
    cin >> b; Max = max(a, b);
    cin >> c; Max = max(Max, c);
    cout << ((a * b * c) / Max) / 2 << endl;
    return(0);
}
