#include <iostream>
using namespace std;

#define ll long long
#define rep(i,n) for (int i = 0;i < n;i++)

int main() {
    int n;
    cin >> n;
    int m = n * 1.08;

    if (m < 206) cout << "Yay!" << endl;
    else if(m == 206) cout << "so-so" << endl;
    else cout << ":(" << endl;

    return(0);
}
