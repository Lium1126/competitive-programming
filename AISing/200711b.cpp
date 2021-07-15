#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0;i < n;i++)
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> a;
    int cnt = 0;
    int input;
    rep(i, n) {
        cin >> input;
        a.push_back(input);
    }

    for (int i = 0;i < a.size();i += 2) {
        if (a[i] % 2) cnt++;
    }

    cout << cnt << endl;

    return(0);
}
