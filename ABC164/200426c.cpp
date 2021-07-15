#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    string str;
    set<string> s;

    for (int i = 0;i < n;i++) {
        cin >> str;
        s.insert(str);
    }

    cout << s.size() << endl;

    return 0;
}
