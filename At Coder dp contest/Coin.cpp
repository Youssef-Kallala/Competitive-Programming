
// https://atcoder.jp/contests/ndpc/tasks/ndpc2026_h

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
    cin>>n;
    string grid[n];
    for (int i=0;i<n;++i)
    {
        cin>>grid[i];
    }
    vector<vector<int>>dpmn(n,vector<int>(n,1e9));
    vector<vector<int>>dpmax(n,vector<int>(n,0));
    dpmn[0][0]=0;
    dpmax[0][0]=0;
    int dx[]={-1,0},dy[]={0,-1};
     
    for (int i=0;i<n;++i)
    {
        for (int j=0;j<n;++j)
        {
            for (int k=0;k<2;++k)
            {
                int nx=i+dx[k],ny=j+dy[k];
                if (nx<0 || ny<0)continue; 
                int c=(grid[i][j]=='@');
                dpmn[i][j]=min(dpmn[i][j],c+dpmn[nx][ny]);
                dpmax[i][j]=max(dpmax[i][j],c+dpmax[nx][ny]);
            }
        }
    }
    vector<int>v(2*n+5,0);
    for (int i=0;i<n;++i)
    {
        for (int j=0;j<n;++j)
        {
            v[dpmn[i][j]]++;
            v[dpmax[i][j]+1]--;
        }
    }
    for (int i=1;i<2*n;++i)v[i]+=v[i-1];
    for (int i=0;i<2*n-1;++i)cout<<v[i]<<'\n';
}
