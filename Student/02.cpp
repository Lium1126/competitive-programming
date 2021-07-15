#include <iostream>
#include <set>
using namespace std;

int main() {
    std::set<int> s;

    int n, m;
    cin >> n >> m;

    int temp;

    for (int i = 0;i < n;i++) {
        cin >> temp;
        s.insert(temp);
    }

    decltype(s)::iterator it;

    for (int i = 0;i < m;i++) {
        cin >> temp;
        it = s.find(temp);
        if (it != s.end()) {
            s.erase(it);
        } else {
            s.insert(temp);
        }
    }

    int i = 0;
    for (it = s.begin();it != s.end();it++) {
        if(i == s.size() - 1) {
            cout << *it << endl;
        } else {
            cout << *it << ' ';
        }
        i++;
    }    

    return 0;
}