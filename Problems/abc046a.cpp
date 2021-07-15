#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> s;
    int in;
    for (int i = 0;i < 3;i++) {
        cin >> in;
        s.insert(in);
    }
    cout << s.size() << endl;
    return(0);
}
