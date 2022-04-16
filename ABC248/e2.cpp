#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)

using namespace std;

class P {
private:
	double x, y;

public:
	P(double _x = 0.0, double _y = 0.0) : x(_x), y(_y) {}

	P operator+(P b) { return P(this->x + b.x, this->y + b.y); }
	P operator-(P b) { return P(this->x - b.x, this->y - b.y); }
	P operator*(double s) { return P(this->x * s, this->y * s); }
	bool operator==(P b) { return this->x == b.x && this->y == b.y; }
	bool operator<(P b) const { if (this->x != b.x) return this->x < b.x; else return this->y < b.y; }

	double getX() const { return this->x; }
	void setX(double _x) { this->x = _x; }
	double getY() const { return this->y; }
	void setY(double _y) { this->y = _y; }

	double dist(P b) {
		return sqrt(pow(this->x - b.x, 2.0) + pow(this->y - b.y, 2.0));
	}

	double size() {
		return sqrt(pow(this->x, 2.0) + pow(this->y, 2.0));
	}

	double innerProduct(P b) {
		return this->x * b.x + this->y * b.y;
	}

	double crossProduct(P b) {
		return abs(this->x * b.y - this->y * b.x);
	}
};

//bool compareY(P a, P b) { return a.getY() < b.getY(); }

int main() {
	ll n, k;
	cin >> n >> k;
	vector<P> v(n);
	set<pair<double, double>> ans;
	double x, y;
	rep(i, n) {
		cin >> x >> y;
		v[i] = P{x, y};
	}

	if (k == 1) cout << "Infinity" << endl;
	else {
		rep(i, n) {
			rep(j, n) {
				if (i == j) continue;

				ll cnt = 2;
				rep(ii, n) {
					if (ii == i || ii == j) continue;
					P a = v[i], b = v[j], p = v[ii];
					if ((p - a).innerProduct(b - a) == 0) cnt++;
				}
				if (cnt >= k) {
					double d, r;
					if (v[i].getX() == v[j].getX()) d = __DBL_MAX__;
					else d = (v[j].getY() - v[i].getY()) / (v[j].getX() - v[i].getX());
					if (v[i].getX() == v[j].getX()) r = v[i].getX();
					else r = v[j].getY() - d * v[j].getX();
					ans.insert(make_pair(d, r));
				}
			}
		}
		cout << ans.size() << endl;
	}

	return 0;
}