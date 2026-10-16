// https://codeforces.com/contest/2275/problem/F

#include <bits/stdc++.h>
using namespace std;
vector<int> spf(1e6 + 1);

vector<int> sieve(int n = 1e6)
{

    for (int i = 0; i <= n; i++)
        spf[i] = i;

    for (long long i = 2; i * i <= n; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j <= n; j += i)
            {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }

    return spf;
}

map<int, int> prime_factorization(int n)
{
    map<int, int> factors;

    while (n > 1)
    {
        int p = spf[n];
        factors[p]++;

        n /= p;
    }
    map<int, int> m;
    for (auto &[x, y] : factors)
    {
        if (y % 2)
            m[x] = 1;
    }
    return m;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<map<int, int>> v(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        v[i] = prime_factorization(a[i]);
    }
    map<long long, long long> occ;
    for (int i = 0; i < n; ++i)
    {
        int ans = 1;
        for (auto &[x, y] : v[i])
        {
            ans *= x;
        }
        occ[ans]++;
    }
    map<int, int> m;
    long long output = 0;
    for (int i = 0; i < n; ++i)
    {
        for (auto &[x, y] : v[i])
        {
            m[x]++;
            if (m[x] == 2)
            {
                m.erase(x);
            }
        }
        int tot = 1, barrier = 1e6 + 1;
        if (m.size() <= 8)
        {
            for (auto &[x, y] : m)
            {
                if (tot > barrier / x)
                {
                    tot = barrier + 1;
                    break;
                }
                else
                {
                    tot *= x;
                }
            }
            if (occ.find(tot) != occ.end())
            {
                output += occ[tot];
            }
        }
    }
    cout << output << '\n';
}
signed main()
{
    sieve();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}