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

typedef pair<ll, ll> P;

ll crossProduct(ll ax, ll ay, ll bx, ll by) {
	return ax * by - ay * bx;
}

int main() {
	P A, B, C, D;
	cin >> A.first >> A.second;
	cin >> B.first >> B.second;
	cin >> C.first >> C.second;
	cin >> D.first >> D.second;

	/*
	4つの外積
	ABxAC,ABxAD,CDxCA,CDxCB
	を計算する
	*/
	// 外積の正負により回転方向を求めることができる
	ll cross1 = crossProduct(B.first - A.first, B.second - A.second, C.first - A.first, C.second - A.second);
	ll cross2 = crossProduct(B.first - A.first, B.second - A.second, D.first - A.first, D.second - A.second);
	ll cross3 = crossProduct(D.first - C.first, D.second - C.second, A.first - C.first, A.second - C.second);
	ll cross4 = crossProduct(D.first - C.first, D.second - C.second, B.first - C.first, B.second - C.second);

	/*
	上記の外積が全て0の場合は、4つの点が一直線上に並んでいる
	*/
	if (cross1 == 0 && cross2 == 0 && cross3 == 0 && cross4 == 0) {
		// 必ずa < b, c < dであるようにする
		if (A > B) swap(A, B);
		if (C > D) swap(C, D);

		/*
		2つのベクトルの左下側(小さい方つまりA,C)のうち大きい方(より右上にある点)が、
		2つのベクトルの右上側(B,D)のうち小さい方より大きければ共有点を持たない
		<<<=======>>>
		・-----・   ・---・
		A      B    C    D

		・-----・   ・---・
		C      D    A    B
		など
		<<<=======>>>
		そうでなければ、共有点を持つ
		<<<=======>>>
		・-----・--・--------・
		A      C   B         D
		など
		<<<=======>>>
		*/
		cout << (max(A, C) <= min(B, D) ? "Yes" : "No") << endl;
	}

	/*
	「A->B->CとA->B->Dの回転方向が逆 = ABxACとABxADの正負が逆」かつ
	「C->D->AとC->D->Bの回転方向が逆 = CDxCAとCDxCBの正負が逆」であれば交差している

	「A->B->CとA->B->Dの回転方向が逆」について：
		回転方向が逆であるならば、A,Bを通る直線で分割される領域について、C,Dは異なる領域にある
		A->BからC,Dに向かう道が分かれるイメージ
	*/
	else {
		bool AB = false, CD = false;
		if (cross1 >= 0 && cross2 <= 0) AB = true;
		if (cross1 <= 0 && cross2 >= 0) AB = true;
		if (cross3 >= 0 && cross4 <= 0) CD = true;
		if (cross3 <= 0 && cross4 >= 0) CD = true;
		
		cout << (AB && CD ? "Yes" : "No") << endl;
	}

	return 0;
}