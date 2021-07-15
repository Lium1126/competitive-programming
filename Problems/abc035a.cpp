#include <iostream>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    if (h / 4 * 3 == w) cout << "4:3" << endl;
    else cout << "16:9" << endl;
    return(0);
}
