#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (!((n / 10) % 111) || !((n % 1000) % 111)) cout << "Yes" << endl;
    else cout << "No" << endl;
}
