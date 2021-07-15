#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int,int> P;

string s;
int mem[200001][200001] = {};

int parseint(int i, int j) {
    int a = 0;
    for(int k = i;k <= j;k++) {
        a *= 10;
        a += (s[k] - '0');
    }
    return a;
}

int main() {
    cin >> s;
    int temp, ans = 0;

    queue<P> que;
    que.push((P){1, s.length()});
    while (!que.empty()) {
        P deq = que.front(); que.pop();
        if (mem[deq.first][deq.second] == 0) {
            mem[deq.first][deq.second] = 1;
            temp = parseint(deq.first - 1, deq.second - 1);
            if (temp % 2019 == 0){
                ans++;
            }
        }
        if (deq.second - deq.first > 4) {
            que.push((P){deq.first + 1, deq.second});
            que.push((P){deq.first, deq.second - 1});
        }
    }

    cout << ans << endl;

    return 0;
}
