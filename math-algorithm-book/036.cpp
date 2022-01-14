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

double degToRad(double deg) { return (M_PI * deg) / 180.0; }

int main() {
	double a, b;
	ll h, m;
	cin >> a >> b >> h >> m;

	P lng = P(cos(degToRad(0.5 * (double)(h * 60 + m))), sin(degToRad(0.5 * (double)(h * 60 + m)))) * a;
	P shrt = P(cos(degToRad(6.0 * (double)(m))), sin(degToRad(6.0 * (double)(m)))) * b;

	printf("%.12lf\n", lng.dist(shrt));

	return 0;
}