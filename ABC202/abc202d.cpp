#include <iostream>
#include <math.h>
using namespace std;

string ans;

void solve(long long a, long long b, long long k) {
    // cout << "a:" << a << ", b:" << b << ", k:" << k << endl;
    long long l = a + b;
    long long n = (long long)pow(2, l); // 長さlの文字列の通り数
    long long m = (long long)((n + a) / (a + 1)); // 16通りの文字列のうち、'a'がa文字のものの通り数
    // cout << "l:" << l << ", n:" << n << ", m:" << m << endl;

    if ((double)k <= (double)(m / 2)) {
        if (a > 0) { ans += 'a'; a--; }
        else { ans += 'b'; b--; }
        if (a == 0 && b == 0) return;
        else { solve(a, b, abs(m / 2 - k)); } // 再帰呼び出し
    } else {
        if (b > 0) { ans += 'b'; b--; }
        else { ans += 'a'; a--; }
        if (a == 0 && b == 0) return;
        else { solve(a, b, abs(m / 2 - k)); } // 再帰呼び出し
    }
}

int main() {
    // aとbしかないから2分探索していきそう
    long long a, b, k;
    cin >> a >> b >> k;
    solve(a, b, k);
    cout << ans << endl;
    return(0);
}
