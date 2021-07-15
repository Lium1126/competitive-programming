#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> s;
    int in;
    for (int i = 0;i < 3;i++) {
        cin >> in;
        if (i == 0) s.insert(in);
        else {
            if (s.find(in) != s.end()) s.erase(in);
            else s.insert(in);
        }
    }
    cout << *s.begin() << endl;
    return(0);
}
