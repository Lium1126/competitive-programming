#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0;i < n;i++)
using ll = long long;
using namespace std;

int main() {
    int n;
    int flag = 0;

    cin >> n;

    while(n != 0) {
        if (n % 10 == 7) {
            flag = 1;
        }
        n /= 10;
    }

    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}
