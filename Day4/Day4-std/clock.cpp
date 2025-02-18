#include<bits/stdc++.h>
using namespace std;

const int Day=24*60*60;

int calc(vector<int> a, int n)
{
    int ans=(int)(1e9);
    for (int i=0,j=n-1; i<n; ++i,j=(j+1)%n)
    {
        int tmp=0;
        if (a[i]<=0) tmp=-a[i]*2;
        else tmp=2*(Day-a[i]);
        if (a[j]<=0) tmp+=Day+a[j];
        else tmp+=a[j];
        ans=min(ans, tmp);
    }
    return ans;
}

int main()
{
    freopen("clock.in", "r", stdin);
    freopen("clock.out", "w", stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n; vector<int> t(3); char ch;
    vector<int> a(n);
    for (int i=0; i<n; ++i)
    {
        cin >> t[0] >> ch >> t[1] >> ch >> t[2];
        a[i] = t[0]*3600+t[1]*60+t[2];
    }
    cin >> t[0] >> ch >> t[1] >> ch >> t[2];
    int T0 = t[0]*3600+t[1]*60+t[2];
    for (auto &x : a) x -= T0;
    a.push_back(0); ++n;
    sort(a.begin(), a.end());
    int ans = calc(a, n);
    reverse(a.begin(), a.end()); for(auto &x : a) x=-x;
    ans = min(ans, calc(a, n));
    int H=ans/3600, m=(ans%3600)/60, s=ans%60;
    cout<<setw(2)<<setfill('0')<<H<<":"
        <<setw(2)<<setfill('0')<<m<<":"
        <<setw(2)<<setfill('0')<<s<<"\n";
}