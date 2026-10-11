#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> b[i];
    }
    if (n == 1)
    {
        cout << 1 + (a[0] == b[0]) << '\n';
        return;
    }
    int suffx[n + 5][2];
    for (int i = n - 1; i >= 0; --i)
    {
        if (i == n - 1)
        {
            suffx[n - 1][0] = 1 + (a[i] == b[i]);
            suffx[n - 1][1] = 1 + (a[i] == b[i]);
        }
        else
        {
            suffx[i][0] = 2 + (a[i] == b[i + 1]) + (b[i] == a[i + 1]) + suffx[i + 1][1];
            suffx[i][1] = 2 + (b[i] == a[i + 1]) + (a[i] == b[i + 1]) + suffx[i + 1][0];
        }
    }
    int prfx[n + 1];
    for (int i = 0; i < n; ++i)
    {
        if (i == 0)
        {
            prfx[i] = 2 + (a[i] == b[i]) + (b[i] == a[i + 1]);
        }
        else if (i == n - 1)
        {
            prfx[i] = 1 + (a[i] == b[i]) + prfx[i - 1];
        }
        else
        {
            prfx[i] = prfx[i - 1] + 2 + (a[i] == b[i]) + (b[i] == a[i + 1]);
        }
    }
    int ans = max(prfx[n - 1], suffx[0][0]);
    for (int i = 0; i < n - 1; ++i)
    {
        ans = max(ans, prfx[i] + suffx[i + 1][0]);
    }
    cout << ans << '\n';
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}