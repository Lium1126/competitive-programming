#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0;i < n;i++)

int main() {
    string s, t;
    cin >> s;
    cin >> t;
    int ans = INT_MAX;

    for (int i = 0;i <= s.length() - t.length();i++) {
        int tmp = 0;
        for (int j = 0;j < t.length();j++) {
            if (s[i + j] != t[j]) tmp++;
        }
        ans = min(ans, tmp);
    }

    cout << ans << endl;

    return (0);
}
