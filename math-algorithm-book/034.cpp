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

bool compareY(P a, P b) { return a.getY() < b.getY(); }

double closestPointPair(vector<P> &points, ll l, ll r) {
	if (r - l <= 1) return __DBL_MAX__;

	ll mid = (l + r) / 2;
	double x = points[mid].getX();
	double d = min(closestPointPair(points, l, mid), closestPointPair(points, mid, r));
	auto itr_begin = points.begin();
	auto itr_l = itr_begin + l, itr_mid = itr_begin + mid, itr_r = itr_begin + r;
	inplace_merge(itr_l, itr_mid, itr_r, compareY);

	vector<P> near_line;

	for (ll i = l;i < r;i++) {
		if (abs(points[i].getX() - x) >= d) continue;

		ll sz = near_line.size();
		for (ll j = sz - 1;j >= 0;j--) {
			double dx = points[i].getX() - near_line[j].getX();
			double dy = points[i].getY() - near_line[j].getY();
			if (dy >= d) break;
			d = min(d, points[i].dist(near_line[j]));
		}
		near_line.push_back(points[i]);
	}

	return d;
}

int main() {
	ll n;
	cin >> n;

	vector<P> points;
	double x, y;
	rep(i, n) {
		cin >> x >> y;
		points.push_back(P{x, y});
	}

	sort(points.begin(), points.end(), [](P &a, P &b) {
		if (a.getX() != b.getX()) return a.getX() < b.getX();
		else return a.getY() < b.getY();
	});

	printf("%.12lf\n", closestPointPair(points, 0, n));
	
	return 0;
}