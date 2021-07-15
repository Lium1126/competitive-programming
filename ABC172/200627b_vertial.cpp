#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define SIZE (200005)

int main() {
    char s[SIZE], t[SIZE];
    cin >> s >> t;
    int ans = 0;
    for (int i = 0;i < strlen(s);i++) if (s[i] != t[i]) ans++;
    cout << ans << endl;
    return 0;
}
