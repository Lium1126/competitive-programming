#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define SIZE (200005)

int main() {
    char s[SIZE], t[SIZE];
    cin >> s >> t;
    int cnt = 0;

    for (int i = 0;i < strlen(s);i++) {
        if(s[i] != t[i]) cnt++;
    }

    cout << cnt << endl;

    return 0;
}
