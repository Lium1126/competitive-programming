#include <iostream>
using namespace std;

int main() {
    double a, b;
    double ans = 0;
    for (int i = 0;i < 3;i++) {
        cin >> a >> b;
        ans += a * (b / 10);
    }
    cout << ans << endl;
    return(0);
}
