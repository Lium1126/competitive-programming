#include <iostream>
using namespace std;

int main() {
    int n, D, H;

    cin >> n >> D >> H;

    int d, h;
    double ans = 0;

    for (int i = 0;i < n;i++) {
        cin >> d >> h;
        int x = D - d;
        double a = (double)(H - h) / x;
        double b = (double)H - a * (double)D;
        ans = max(ans, b);
    }

    cout << ans << endl;

    return(0);
}
