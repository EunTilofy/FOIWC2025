#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("fruit.in", "r", stdin);
    freopen("fruit.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    set<pair<int,int>> S;
    double ans = -1e9;
    cout << fixed << setprecision(2);
    for (int i=0; i<n; ++i)
    {
        int x, y; cin >> x >> y;
        if (i > 0)
        {
            auto it = S.lower_bound({y, x});
            if (it != S.end())
            {
                ans = max(ans, (double)(x - it->second) / (y - it->first));
            }
            if (it != S.begin())
            {
                --it;
                ans = max(ans, (double)(x - it->second) / (y - it->first));
            }
            cout << ans <<   " ";
        }
        S.insert({y, x});
    }
}