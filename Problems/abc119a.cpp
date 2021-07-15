#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    int temp = 0;
    for (int i = 0;i < s.length();i++) {
        if ('0' <= s[i] && s[i] <= '9') {
            temp *= 10;
            temp += s[i] - '0';
        }
    }
    if (temp > 20190430) cout << "TBD" << endl;
    else cout << "Heisei" << endl;
    return(0);
}
