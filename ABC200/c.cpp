#include <iostream>
using namespace std;

int main() {
    long long n;
    long long input;
    long long ans = 0;

    pair<long long, long long> p[200];
    for (int i = 0;i < 200;i++) {
        p[i].first = 0;
        p[i].second = 0;
    }

    cin >> n;

    for (long long i = 0;i < n;i++) {
        cin >> input;
        if ((input / 100) % 2 == 0) p[input % 100].first++;
        else p[input % 100].second++;
    }

    for (int i = 0;i < 200;i++) {
        ans += (p[i].first * (p[i].first - 1)) / 2;
        ans += (p[i].second * (p[i].second - 1)) / 2; 
//        cout << i << ":first=" << p[i].first << ", second=" << p[i].second << endl;
    }

    cout << ans << endl;

    return 0;
}