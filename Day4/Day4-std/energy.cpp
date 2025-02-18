#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll INF=3e18;
ll f[2][80][80];
int main()
{
    freopen("energy.in", "r", stdin);
    freopen("energy.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T;
    cin >> T;
    while(T--)
    {
        int n; cin >> n;
        vector<ll> a(n);
        for (auto &x : a) cin >> x;
        for (int i=0; i<n; ++i) a.push_back(a[i]);
        for (int i=0; i<n*2; ++i) f[0][i][i] = f[1][i][i] = a[i];
        for (int i=n*2-2; i>=0; --i)
        for (int j=i+1; j<i+n && j<n*2; ++j)
        {
            f[0][i][j] = -INF;
            f[1][i][j] = INF;
            // case1
            for (int k=i; k<j; ++k)
            {
                f[0][i][j] = max(f[0][i][j], f[0][i][k] + f[0][k+1][j]);
                f[1][i][j] = min(f[1][i][j], f[1][i][k] + f[1][k+1][j]);
            }
            // case2
            for (int k1=i; k1<j; ++k1) for (int k2=k1+1; k2<j; ++k2)
            {
                vector<ll> tmp;
                for (int x : {0, 1}) for (int y : {0, 1}) tmp.push_back(f[x][i][k1] * f[y][k2+1][j]);
                sort(tmp.begin(), tmp.end());
                f[0][i][j] = max(f[0][i][j], tmp[3]-f[1][k1+1][k2]);
                f[1][i][j] = min(f[1][i][j], tmp[0]-f[0][k1+1][k2]);
            }
        }
        ll ans=f[0][0][n-1];
        for (int i=1; i<n; ++i) ans = max(ans, f[0][i][i+n-1]);
        cout << ans << "\n";
    }
}