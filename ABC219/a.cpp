#include <iostream>
using namespace std;

#define ll long long
#define rep(i, n) for (ll i = 0; i < n; i++)

int main()
{
    int n;
    cin >> n;
    if (0 <= n && n < 40)
        cout << 40 - n << endl;
    else if (40 <= n && n < 70)
        cout << 70 - n << endl;
    else if (70 <= n && n < 90)
        cout << 90 - n << endl;
    else if (90 <= n)
        cout << "expert" << endl;

    return 0;
}
