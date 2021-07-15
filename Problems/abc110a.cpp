#include <iostream>
using namespace std;

int main() {
    int a[3] = {}, max_p = 0;
    for (int i = 0;i < 3;i++) {
        cin >> a[i];
        if (a[max_p] <= a[i]) max_p = i;
    }
    cout << a[max_p] * 10 + (a[0] + a[1] + a[2]) - a[max_p] << endl;
    return(0);
}
