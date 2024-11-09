#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stdio.h>
#include <math.h>
#include <atcoder/all>

#include <boost/multiprecision/cpp_int.hpp>
namespace mp = boost::multiprecision;
using Bint = mp::cpp_int;

#define ll long long
#define rep(i, n)     for (ll i = 0;i < n;i++)
#define rrep(i, n)    for (ll i = n - 1;i >= 0;i--)
#define irep(i, n)    for (ll i = 1;i <= n;i++)
#define rirep(i, n)   for (ll i = n;i >= 1;i--)
#define srep(i, s, n) for (ll i = s;i <= n;i++)

using namespace std;
using namespace atcoder;
typedef pair<ll, ll> P;

vector<int> convert(ll n) {
	vector<int> ret;
	while (n != 0) {
		ret.push_back(n % 10);
		n /= 10;
	}
	// reverse(ret.begin(), ret.end());

	return ret;
}

vector<int> carry_and_fix(vector<int> digit) {
	int N = digit.size();
	for(int i = 0; i < N - 1; ++i) {
		// 繰り上がり処理 (K は繰り上がりの回数)
		if(digit[i] >= 10) {
			int K = digit[i] / 10;
			digit[i] -= K * 10;
			digit[i + 1] += K;
		}
		// 繰り下がり処理 (K は繰り下がりの回数)
		if(digit[i] < 0) {
			int K = (-digit[i] - 1) / 10 + 1;
			digit[i] += K * 10;
			digit[i + 1] -= K;
		}
	}
	// 一番上の桁が 10 以上なら、桁数を増やすことを繰り返す
	while(digit.back() >= 10) {
		int K = digit.back() / 10;
		digit.back() -= K * 10;
		digit.push_back(K);
	}
	// 1 桁の「0」以外なら、一番上の桁の 0 (リーディング・ゼロ) を消す
	while(digit.size() >= 2 && digit.back() == 0) {
		digit.pop_back();
	}
	return digit;
}

vector<int> add(vector<int> digit_a, vector<int> digit_b) {
	int N = max(digit_a.size(), digit_b.size()); // a と b の大きい方
	vector<int> digit_ans(N); // 長さ N の配列 digit_ans を作る
	for(int i = 0; i < N; ++i) {
		digit_ans[i] = (i < digit_a.size() ? digit_a[i] : 0) + (i < digit_b.size() ? digit_b[i] : 0);
		// digit_ans[i] を digit_a[i] + digit_b[i] にする (範囲外の場合は 0)
	}
	return carry_and_fix(digit_ans); // 2-4 節「繰り上がり計算」の関数です
}

vector<int> multiple(vector<int> digit_a, vector<int> digit_b) {
	int NA = digit_a.size(); // A の桁数
	int NB = digit_b.size(); // B の桁数
	vector<int> res(NA + NB - 1);
	for(int i = 0; i < NA; ++i) {
		for(int j = 0; j < NB; ++j) {
			res[i+j] += digit_a[i] * digit_b[j];
			// 答えの i+j の位に digit_a[i] * digit_b[j] を足す
		}
	}
	return carry_and_fix(res);
}

void print(vector<int> n) {
	reverse(n.begin(), n.end());
	for (int d : n) cout << d;
	cout << endl;
}

int main() {
	ll n;
	cin >> n;
	string s;
	cin >> s;

	vector<int> b;
	vector<int> ans;
	ans.push_back(0);
	rirep(i, n) {
		b.push_back(1);
		vector<int> c; c.push_back(s[i - 1] - '0');
		vector<int> idx = convert(i);
		ans = add(ans, multiple(multiple(c, idx), b));
	}

	print(ans);

	return 0;
}