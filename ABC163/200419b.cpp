#include<bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    int n, m;
    int input;
    ll sum = 0;

    cin >> n >> m;

    for(int i = 0;i < m;i++) {
        cin >> input;
        sum +=  input;
    }

    if (sum > n) {
        cout << "-1" << endl;
    } else {
        cout << n - sum << endl;
    }

    return 0;
}
