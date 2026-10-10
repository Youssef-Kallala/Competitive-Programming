// https://codeforces.com/contest/2275

#include <bits/stdc++.h>
using namespace std;
#define int long

void solve()
{
    long long n, k;
    cin >> n >> k;
    long long a[n], b[n], c[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i] >> b[i] >> c[i];
    }
    long long l = -4e18, r = 4e18;
    long long ans = 3e18;
    for (int i = 0; i < n; ++i)
        ans = min(ans, a[i] + b[i] + c[i]);
    while (l <= r)
    {
        long long mid = (l + r) / 2;
        long long tot = 0;
        for (int i = 0; i < n; ++i)
        {
            if (a[i] + b[i] + c[i] >= mid)
                continue;
            if (a[i] == b[i] && c[i] == b[i])
            {
                tot = k + 1;
                break;
            }
            if (a[i] <= b[i] && b[i] <= c[i])
            {
                tot += min(b[i] - a[i], c[i] - b[i]) + 1ll;
                tot += mid - (a[i] + b[i] + c[i] - min(b[i] - a[i], c[i] - b[i]) - 1ll);
            }
            else
            {
                tot += mid - (a[i] + b[i] + c[i]);
            }
            if (tot > k)
                break;
        }
        if (tot <= k)
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
