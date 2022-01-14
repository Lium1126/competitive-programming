#include <iostream>
#include <vector>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)

using namespace std;

ll n;
vector<ll> a(200009), c(200009);

void MergeSort(ll l, ll r) {
	if (r - l == 1) return;

	ll m = (l + r) / 2;
	MergeSort(l, m);
	MergeSort(m, r);

	ll c1 = l, c2 = m, cnt = 0;
	while(c1 != m || c2 != r) {
		if (c1 == m) c[cnt] = a[c2], c2++;
		else if (c2 == r) c[cnt] = a[c1], c1++;
		else {
			if (a[c1] < a[c2]) c[cnt] = a[c1], c1++;
			else c[cnt] = a[c2], c2++;
		}
		cnt++;
	}

	for (ll i = 0;i < cnt;i++) a[l + i] = c[i];
}

int main() {
	cin >> n;
	for (ll i = 1;i <= n;i++) cin >> a[i];

	MergeSort(1, n + 1);
	for (ll i = 1;i <= n;i++) cout << a[i] << (i == n ? '\n' : ' ');

	return 0;
}