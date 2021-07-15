#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n % 3 == 0) {
        cout << "YES" << endl;
    } else {
        bool flag = true;
        while(n != 0 && flag) {
            if (n % 10 == 3) flag = false;
            n /= 10;
        }    
        if (flag) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return(0);
}
