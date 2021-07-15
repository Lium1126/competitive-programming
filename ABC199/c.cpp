#include <iostream>
using namespace std;

int main() {
    int n, q, t, a, b;

    cin >> n;

    string input;
    string s1, s2;
    char temp;
    int swap = 0;

    cin >> input;
    s1 = input.substr(0, n);
    s2 = input.substr(n);

    cin >> q;

    for (int i = 0;i < q;i++) {
        cin >> t >> a >> b;
        a--; b--;
        if (t == 1) {
            if (swap == 0) {
                if (a < n && b < n) {
                    temp = s1[a];
                    s1[a] = s1[b];
                    s1[b] = temp;
                } else if (a < n && b >= n) {
                    b %= n;
                    temp = s1[a];
                    s1[a] = s2[b];
                    s2[b] = temp;
                } else if (a >= n && b < n) {
                    a %= n;
                    temp = s2[a];
                    s2[a] = s1[b];
                    s1[b] = temp;
                } else {
                    a %= n; b %= n;
                    temp = s2[a];
                    s2[a] = s2[b];
                    s2[b] = temp;
                }
            } else {
                if (a < n && b < n) {
                    temp = s2[a];
                    s2[a] = s2[b];
                    s2[b] = temp;
                } else if (a < n && b >= n) {
                    b %= n;
                    temp = s2[a];
                    s2[a] = s1[b];
                    s1[b] = temp;
                } else if (a >= n && b < n) {
                    a %= n;
                    temp = s1[a];
                    s1[a] = s2[b];
                    s2[b] = temp;
                } else {
                    a %= n; b %= n;
                    temp = s1[a];
                    s1[a] = s1[b];
                    s1[b] = temp;
                }
            }
        } else {
            swap = (swap + 1) % 2;
        }
/*
        if (swap == 0) cout << s1 << ":" << s2 << endl;
        else cout << s2 << ":" << s1 << endl;
*/
    }

    if (swap == 0) cout << s1 << s2 << endl;
    else cout << s2 << s1 << endl;

    return(0);
}
