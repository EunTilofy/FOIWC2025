#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    freopen("running.in", "r", stdin);
    freopen("running.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    vector<int> a, b;
    for (int i=0; i<n; ++i)
    {
        int ai, bi, ci; cin >> ai >> bi >> ci;
        int sum = 0, x = 1;
        while (sum < ci)
        {
            a.push_back(ai * min(x, ci-sum));
            b.push_back(bi * min(x, ci-sum));
            sum += min(x, ci-sum);
            x *= 2;
        }
    }
    n = a.size();
    vector<ll> F(2*m+1);
    auto f=F.begin()+m;
    fill(F.begin(), F.end(), -1e14);
    f[0] = 0;
    for (int i=0; i<n; ++i)
    {
        ll ai=abs(a[i]), bi=b[i];
        if (a[i] < 0) reverse(F.begin(), F.end());
        for (int j=m; j>=-m+ai; --j)
        {
            f[j] = max(f[j], f[j-ai]+bi);
        }
        if (a[i] < 0) reverse(F.begin(), F.end());
    }
    cout << *max_element(f-m, f+m+1) << "\n";
}