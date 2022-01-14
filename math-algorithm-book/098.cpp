#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)

using namespace std;

class P {
private:
	ll x, y;

public:
	P(ll _x = 0.0, ll _y = 0.0) : x(_x), y(_y) {}

	P operator+(P b) { return P(this->x + b.x, this->y + b.y); }
	P operator-(P b) { return P(this->x - b.x, this->y - b.y); }
	P operator*(ll s) { return P(this->x * s, this->y * s); }
	bool operator==(P b) { return this->x == b.x && this->y == b.y; }

	ll getX() const { return this->x; }
	void setX(ll _x) { this->x = _x; }
	ll getY() const { return this->y; }
	void setY(ll _y) { this->y = _y; }

	ll dist(P b) {
		return sqrt(pow(this->x - b.x, 2.0) + pow(this->y - b.y, 2.0));
	}

	ll size() {
		return sqrt(pow(this->x, 2.0) + pow(this->y, 2.0));
	}

	ll innerProduct(P b) {
		return this->x * b.x + this->y * b.y;
	}

	ll crossProduct(P b) {
		return this->x * b.y - this->y * b.x;
	}
};

using Vector = P;

int main() {
	ll n;
	cin >> n;

	vector<P> p(n);
	ll x, y;
	rep(i, n) {
		cin >> x >> y;
		p[i].setX(x);
		p[i].setY(y);
	}

	P target;
	cin >> x >> y;
	target.setX(x), target.setY(y);

	ll cnt = 0;
	rep(i, n) {
		Vector AT = p[i] - target, BT = p[(i + 1) % n] - target;
		if (AT.getY() > BT.getY()) swap(AT, BT);
		if (AT.getY() <= 0 && 0 < BT.getY() && BT.crossProduct(AT) < 0) cnt++;
	}

	cout << ((cnt & 1) ? "INSIDE" : "OUTSIDE") << endl;

	return 0;
}