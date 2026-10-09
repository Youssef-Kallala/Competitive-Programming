//https://atcoder.jp/contests/ndpc/tasks/ndpc2026_d

#include <bits/stdc++.h>
using namespace std;
string n;
vector<array<array<int,2>,2>> memo;   // memo[i][bigger][carry]

int rec(int i,int bigger,int carry)
{
    if (i==-1)
    {
        if (bigger)
            return 0;
        return 1;
    }
    int &res = memo[i][bigger][carry];   // key taken from the original arguments
    if (res != -1)
        return res;

    int c=n[i]-'0';
    int r=c+carry;
    if (r==10)
    {
        int ans=1e9;
        for (int d=0;d<=9;++d)
        {
            ans=min(ans,2*d+rec(i-1,0,1));
        }
        return res = ans;
    }
    int ans=1e9;
    for (int d=0;d<=9;++d)
    {
        if (d<r)
        {
            ans=min(ans,2*d-r+10+rec(i-1,0,1));
        }
        else if (d==r)
        {
            if (carry)
            {
                bigger=1;
            }
            ans=min(ans,d+rec(i-1,bigger,0));
        }
        else if (d>r)
        {
            ans=min(ans,2*d-r+rec(i-1,1,0));
        }
    }
    return res = ans;
}

void solve()
{
    cin>>n;
    memo.assign(n.size(), {});                       // fresh memo for this test
    for (auto &a : memo) for (auto &b : a) b.fill(-1);
    cout<<rec(n.size()-1,1,0)<<"\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while (T--)
        solve();
}