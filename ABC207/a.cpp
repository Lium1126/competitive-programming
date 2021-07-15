#include <iostream>
using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0;i < n;i++)

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << max(a + b, max(b + c, c + a)) << endl;
    return 0;
}
