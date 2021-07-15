#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int ans = 1;
    for (int i = 1; i <= (b - a);i++) {
        int temp = a;
        while(temp % i != 0) {
            temp++;
        }
        if ((temp + i) <= b && ans < i) ans = i;
    }

    cout << ans << endl;

    return 0;
}