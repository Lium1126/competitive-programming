#include <iostream>
using namespace std;

int main() {
    int c[11] = {};
    int in;
    for (int i = 0;i < 3;i++) {
        cin >> in;
        c[in]++;
    }
    if (c[5] == 2 && c[7] == 1) cout << "YES" << endl;
    else cout << "NO" << endl;
    return(0);
}
