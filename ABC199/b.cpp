#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    int input;

    int amax = 0;
    int bmin = INT32_MAX;

    cin >> n;
    for (int i = 0;i < n;i++) {
        cin >> input;
        if (amax < input) amax = input;
    }

    for (int i = 0;i < n;i++) {
        cin >> input;
        if (bmin > input) bmin = input;
    }

    int ans = 0;
    if (amax <= bmin) ans = (bmin - amax) + 1;

    cout << ans << endl;

    return(0);
}
