#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string s;
int sum[200005] = {};

int parseint(int i, int j) {
    int a = 0;
    for(int k = 0;k <= j;k++) {
        a *= 10;
        a += (s[i + k] - '0');
    }
    return a;
}

int main() {
    cin >> s;
    int temp, ans = 0;

    for (int i = 1;i <= s.length();i++) {
        sum[i] = sum[i - 1] + (s[i - 1] - '0');
    }

    for (int i = 1;i <= s.length();i++) {
        for (int j = 3;i + j <= s.length();j++) {
            //cout << i << ' ' << i + j << ' ' << sum[i + j] - sum[i - 1] << endl;
            if ((sum[i + j] - sum[i - 1]) % 3 == 0) {
                temp = parseint(i - 1, j);
                if (temp % 2019 == 0) {
                    ans++;
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}
