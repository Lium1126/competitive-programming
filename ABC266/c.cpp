#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>

#define ll long long

using namespace std;

// Point in the xy-plane
struct PointType{
    double x;
    double y;
};


// Sort criterion: points are sorted with respect to their x-coordinate.
//                 If two points have the same x-coordinate then we compare
//                 their y-coordinates
bool sortPoints(const PointType &lhs, const PointType &rhs) 
{ 
    return (lhs.x < rhs.x) || (lhs.x==rhs.x && lhs.y < rhs.y); 
}

// Check if three points make a right turn using cross product
bool right_turn(const PointType &P1, const PointType &P2, const PointType &P3)
{
    return ((P3.x-P1.x)*(P2.y-P1.y) - (P3.y-P1.y)*(P2.x-P1.x)) > 0;
}

int main () {
    int n_points = 4;
    PointType points[4];
    vector<PointType> lowerCH;
    vector<PointType> upperCH;
    
	for (int i = 0;i < 4;i++) {
		cin >> points[i].x >> points[i].y;
	}

	//Sorting points
	sort(points, points + n_points, sortPoints);

	//Computing upper convex hull
	upperCH.push_back(points[0]);
	upperCH.push_back(points[1]);
	
	for(int i=2; i<n_points; i++)
	{
		while(upperCH.size() > 1 and (!right_turn(upperCH[upperCH.size()-2],upperCH[upperCH.size()-1], points[i])))
			upperCH.pop_back();
		upperCH.push_back(points[i]);
	}

	//Computing lower convex hull
	lowerCH.push_back(points[n_points-1]);
	lowerCH.push_back(points[n_points-2]);
	
	for(int i=2; i< n_points; i++)
	{
		while(lowerCH.size() > 1 and (!right_turn(lowerCH[lowerCH.size()-2],lowerCH[lowerCH.size()-1], points[n_points-i-1])))
			lowerCH.pop_back();
		lowerCH.push_back(points[n_points-i-1]);
	}

	std::set<pair<ll, ll>> s;
	for(int i=0; i < upperCH.size(); i++) {
		s.insert(make_pair(upperCH[i].x, upperCH[i].y));
	}
	for(int i=0; i < lowerCH.size(); i++) {
		s.insert(make_pair(lowerCH[i].x, lowerCH[i].y));
	}
	cout << (s.size() == 4 ? "Yes" : "No") << endl;

/*
	for (auto itr = s.begin();itr != s.end();itr++) {
		cout << (*itr).first << ' ' << (*itr).second << endl;
	}
*/

    return 0;
}