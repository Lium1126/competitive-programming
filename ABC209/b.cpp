#include <iostream>
using namespace std;

#define ll long long
#define rep(i,n) for (ll i = 0;i < n;i++)

int main() {
    int n, x;
    cin >> n >> x;

    int sum = 0;
    int temp;
    rep(i,n) {
        cin >> temp;
        if ((i + 1) % 2 == 0) sum += (temp - 1);
        else sum += temp;
    }

    if (x >= sum) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
