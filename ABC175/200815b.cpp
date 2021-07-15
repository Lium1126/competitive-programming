#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0;i < n;i++)

int main() {
    int n;
    cin >> n;
    int input;
    vector<int> l;
    rep(i, n) {
        cin >> input;
        l.push_back(input);
    }

    int ans = 0;
    rep (i, l.size() - 2) {
        for (int j = i + 1;j < l.size() - 1;j++) {
            for (int k = j + 1;k < l.size();k++) {
                if ((l[i] != l[j] && l[j] != l[k] && l[k] != l[i])) {
                    int a, b, c;
                    if (l[i] > l[j] && l[i] > l[k]) {
                        a = l[i];
                        b = l[j]; c = l[k];
                    }
                    else if (l[j] > l[i] && l[j] > l[k]) {
                        a = l[j];
                        b = l[i]; c = l[k];
                    }
                    else if (l[k] > l[i] && l[k] > l[j]) {
                        a = l[k];
                        b = l[i]; c = l[j];
                    }

                    if (a < b + c) ans++;
                }
            }
        }
    }

    cout << ans << endl;
}
