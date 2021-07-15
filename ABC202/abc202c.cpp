#include <iostream>
#include <vector>
#define rep(i, n) for (long long i = 0;i < n;i++)
using namespace std;

int main() {
    long long n;
    long long ans = 0;
    long long temp;
    vector<long long> b;
    pair<long long, long long> a[100005];
    cin >> n;
    rep(i, 100005) a[i].first = a[i].second = 0;
    rep(i, n) {
        cin >> temp;
        a[temp].first++;
    }
    rep(i, n) {
        cin >> temp;
        b.push_back(temp);
    }
    rep(i, n) {
        cin >> temp;
        a[b[temp - 1]].second++;
    }
    rep(i, 100005) {
        ans += a[i].first * a[i].second;
    }
    cout << ans << endl;
    return(0);
}
