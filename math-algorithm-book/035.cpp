#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <cstdio>
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

using Vector = P;

int main() {
	double x, y, inr;
	vector<P> p(2);
	vector<double> r(2);
	rep(i, 2) {
		cin >> x >> y >> inr;
		p[i] = P(x, y);
		r[i] = inr;
	}

	double d = p[0].dist(p[1]);

	if (d < abs(r[0] - r[1])) cout << 1 << endl;
	else if (d == abs(r[0] - r[1])) cout << 2 << endl;
	else if (d == r[0] + r[1]) cout << 4 << endl;
	else if (d > r[0] + r[1]) cout << 5 << endl;
	else cout << 3 << endl;

	return 0;
}