#include <iostream>
using namespace std;

int main() {
    string a, b, c;
    cin >> a >> b >> c;
    cout << (char)((a[0] - 'a' ) + 'A') << (char)((b[0] - 'a' ) + 'A') << (char)((c[0] - 'a' ) + 'A') << endl;
    return(0);
}
