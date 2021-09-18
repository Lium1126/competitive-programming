#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;

#define ll long long
#define rep(i, n) for (ll i = 0; i < n; i++)

class S
{
public:
    string name;
    string n_name;

    S(string _name = "", string _n_name = "") : name(_name), n_name(_n_name) {}

    bool operator<(S b) const
    {
        return n_name < b.n_name;
    }
};

int main()
{
    string x;
    ll n;
    map<char, char> m;
    set<S> s;
    string y;

    cin >> x;
    rep(i, 26)
    {
        m[x[i]] = 'a' + i;
    }

    cin >> n;

    rep(i, n)
    {
        cin >> y;
        S tmp;
        tmp.name = y;
        rep(j, y.length())
        {
            tmp.n_name += m[y[j]];
        }

        s.insert(tmp);
    }

    for (decltype(s)::iterator itr = s.begin(); itr != s.end(); ++itr)
    {
        cout << (*itr).name << endl;
    }

    return 0;
}
