#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    int ans1, ans2, ans3;
    ans1 = ans2 = ans3 = 1;
    cin >> a;
    cin >> b;
    if (a < b) ans1++;
    else ans2++;
    cin >> c;
    if (a < c) ans1++;
    else ans3++;
    if (b < c) ans2++;
    else ans3++;
    cout << ans1 << endl << ans2 << endl << ans3 << endl;
    return(0);
}
