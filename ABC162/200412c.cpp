#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0;i < n;i++)
using ll = long long;
using namespace std;

int main() {
    int k;
    int sum = 0;

    cin >> k;

    for (int n = 1;n <= k;n++) {
        for (int m = 1;m <= k;m++) {
            for (int l = 1;l <= k;l++) {
                sum += __gcd(__gcd(n, m), l);
            }
        }
    }

    cout << sum << endl;

    return 0;
}
