#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int a[5];
    int ans = 0;
    for (int i = 0;i < 5;i++) {
        cin >> a[i];
        if (a[i] == 0) ans = i;
    }

    cout << ans + 1 << endl;
    
    return 0;
}
