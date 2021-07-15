#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    map<string, int> m;
    
    int n;
    cin >> n;
    string input;

    for (int i = 0;i < n;i++) {
        cin >> input;
        m[input]++;
    }

    cout << "AC x " << m["AC"] << endl;
    cout << "WA x " << m["WA"] << endl;
    cout << "TLE x " << m["TLE"] << endl;
    cout << "RE x " << m["RE"] << endl;
    
    return(0);
}
