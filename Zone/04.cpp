#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string s;
    cin >> s;
    int r = 0;

    vector<char> v1;

    for (int i = 0;i < s.length();i++) {
        if (i == 0) v1.push_back(s[i]);
        else if (s[i] == 'R') r = (r + 1) % 2;
        else {
            if (r == 0) {
                if (v1[v1.size() - 1] == s[i]) {
                    v1.erase(v1.end());
                } else {
                    v1.push_back(s[i]);
                }
            } else {
                if (v1[0] == s[i]) {
                    v1.erase(v1.begin());
                } else {
                    v1.insert(v1.begin(), s[i]);
                }
            }
        }
    }

    int flag = 1;
    while (flag && v1.size() >= 0) {
        flag = 0;

        for (int i = 0;v1.size() >= 2 && i <= v1.size() - 2;i++) {
            if (v1[i] == v1[i + 1] && v1.size() > i + 1) {
                v1.erase(v1.begin() + i);
                v1.erase(v1.begin() + i);
                i--;
                flag = 1;
            }
        }
    }

    if (r == 0) {
        for (int i = 0;i < v1.size();i++) {
            cout << v1[i];
        }
    } else {
        for (int i = v1.size() - 1;i >= 0;i--) {
            cout << v1[i];
        }
    }
    cout << endl;

    return(0);
}
