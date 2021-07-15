#include <iostream>
using namespace std;

int main() {
    int a, n;
    cin >> n >> a;
    if (a >= n % 500) cout << "Yes" << endl;
    else cout << "No" << endl;
    return(0);
}
