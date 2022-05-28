#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)

using namespace std;

class P {
public:
	string s;
	ll number;
	ll score;

	P(string s, ll num, ll score) : s(s), number(num), score(score) {}
	bool operator<(P b) const {
		if (this->score != b.score) return this->score > b.score;
		else return this->number < b.number;
	}
};

int main() {
	ll n, t;
	cin >> n;
	string s;
	map<string, bool> mp;
	vector<P> data;
	rep(i, n) {
		cin >> s >> t;
		if (!mp[s]) {
			mp[s] = true;
			data.push_back(P(s, i + 1, t));
		}
	}

	sort(data.begin(), data.end());

	cout << data[0].number << endl;

	return 0;
}