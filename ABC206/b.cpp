#include <iostream>
using namespace std;

#define ll long long
#define rep(i,n) for (int i = 0;i < n;i++)

int main() {
    int a = 0;
    int n;
    cin >> n;

    while(1) {
        if (((a + 1) * a) / 2 >= n) break;
        a++;
    }

    cout << a << endl;

    return(0);
}
