#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    string n;
    cin >> n;
    ll sum = 0;
    for (int i = 0;i < n.length();i++) {
        sum += (n[i] - '0'); 
    }
    if (sum % 9 == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
    return(0);
}
