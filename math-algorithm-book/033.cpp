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
	vector<P> points(3);
	double x, y;
	rep(i, 3) {
		cin >> x >> y;
		points[i] = P(x, y);
	}

	Vector bc = points[2] - points[1], ba = points[0] - points[1];
	if (bc.innerProduct(ba) < 0) {
		printf("%.12lf\n", ba.size());
		return 0;
	}

	Vector cb = points[1] - points[2], ca = points[0] - points[2];
	if (cb.innerProduct(ca) < 0) {
		printf("%.12lf\n", ca.size());
		return 0;
	}

	printf("%.12lf\n", ba.crossProduct(bc) / bc.size());
	
	return 0;
}