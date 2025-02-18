#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("score.in", "r", stdin);
    freopen("score.out", "w", stdout);
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k; cin >> n >> k;
    vector<int> a(n); for (int i=0; i<n; ++i) cin >> a[i];
    vector<int> b(n+1);
    int ans = 0;
    auto chk = [&] (int x) -> bool
    {
        for (int i=0; i<n; ++i) b[i+1] = b[i] + (a[i] >= x ? 1 : -1);
        int ans = b[k];
        for (int i=k+1; i<n; ++i)
        {
            b[i-k] = min(b[i-k-1], b[i-k]);
            ans = max(ans, b[i] - b[i-k]);
        }
        return ans > 0;
    };
    int l = 1, r = 1e9;
    while (l <= r)
    {
        int mid = (l+r)/2;
        if (chk(mid)) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    cout << ans << "\n";
}