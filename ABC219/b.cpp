#include <iostream>
#include <string>
using namespace std;

#define ll long long
#define rep(i, n) for (ll i = 0; i < n; i++)

int main()
{
    string s1, s2, s3;
    string t;

    cin >> s1 >> s2 >> s3;
    cin >> t;

    rep(i, t.length())
    {
        if (t[i] == '1')
            cout << s1;
        else if (t[i] == '2')
            cout << s2;
        else if (t[i] == '3')
            cout << s3;
    }
    cout << endl;

    return 0;
}