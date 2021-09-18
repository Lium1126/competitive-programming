#include <iostream>
#include <vector>
using namespace std;

#define INF (1 << 30)
#define rep(i, n) for (int i = 0; i < n; i++)

int dp[305][305][305];

int main()
{
    int n;
    int x, y;
    cin >> n;
    cin >> x >> y;
    int a[305], b[305];
    rep(i, n) cin >> a[i] >> b[i];

    rep(i, 305) rep(j, 305) rep(k, 305) dp[i][j][k] = INF;

    rep(i, n + 1)
    {
        rep(j, x + 1)
        {
            rep(k, y + 1)
            {
                if (i == 0)
                {
                    dp[0][0][0] = 0;
                }
                else
                {
                    dp[i][min(j + a[i - 1], x)][min(k + b[i - 1], y)] = min(dp[i][min(j + a[i - 1], x)][min(k + b[i - 1], y)], dp[i - 1][j][k] + 1);
                    dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k]);
                }
            }
        }
    }

    if (dp[n][x][y] == INF)
        cout << -1 << endl;
    else
        cout << dp[n][x][y] << endl;
}
