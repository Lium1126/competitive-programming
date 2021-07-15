#include <iostream>

using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0;i < n;i++)

ll n, k;
string str;

ll cntS(ll idx, string str)
{
    ll cnt = 0;
    for (ll i = idx - 1;i <= idx + 1;i++) {
        if (0 <= i && i < n) {
            if (str[i] == 'S') cnt++;
        }
    }

    return cnt;
}

string updateStr(ll idx, string str)
{
    for (ll i = idx - 1;i <= idx + 1;i++) {
        if (0 <= i && i < n) {
            str[i] = '.';
        }
    }
    return str;
}

ll solve(ll idx, ll sum, ll remain, string s)
{
    if (idx == n) return sum;
    if (remain == 0) return sum;
    if (s[idx] != 'S') return solve(idx + 1, sum, remain, s);
    else return max(solve(idx + 1, sum, remain, s), solve(idx + 1, sum + cntS(idx, str), remain - 1, updateStr(idx, str)));
}

int main()
{
    ll cnt = 0;

    cin >> n >> k;
    cin >> str;

    rep(i, n) if (str[i] == '.') cnt++;

    cout << cnt + solve(0, 0, k, str) << endl;

    return 0;
}
