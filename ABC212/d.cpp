#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define ll long long
#define rep(i,n) for (ll i = 0;i < n;i++)

int main() {
    ll q;
    cin >> q;
    ll p, x;
    std::priority_queue<
        ll,
        std::vector<ll>,
        std::greater<ll>   // 昇順 (デフォルトはstd::less<T>)
    > pque, temp;
    queue<ll> que;
    ll sum = 0;

    rep(i, q) {
        cin >> p;

        switch(p) {
            case 1:
                cin >> x;
                pque.push(x - sum);
                break;
            case 2:
                cin >> x;
                sum += x;
                break;
            case 3:
                que.push(pque.top() + sum);
                pque.pop();
        }
    }

    while (!que.empty()) {
        cout << que.front() << endl;
        que.pop();
    }

    return 0;
}