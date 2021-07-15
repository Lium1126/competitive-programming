#include <iostream>
using namespace std;

int main() {
    long long n;

    cin >> n;

    long long a, b, c, d, e, ans = __LONG_LONG_MAX__;
    long long ma, mb, mc, md, me;
    ma = mb = mc = md = me = 0;

    for (long long i = 0;i < n;i++) {
        cin >> a >> b >> c >> d >> e;
        ma = max(a, ma);
        mb = max(b, mb);
        mc = max(c, mc);
        md = max(d, md);
        me = max(e, me);
    }

    ans = min(ma, min(mb, min(mc, min(md, me))));

    cout << ans << endl;

    return(0);
}