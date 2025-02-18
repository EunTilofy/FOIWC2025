#include <bits/stdc++.h>
using namespace std;
const int p = 1e9+7;

int main()
{
	freopen("mult.in", "r", stdin);
    freopen("mult.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n; cin >> n;
	vector<long long> a(n);
	vector<int> num(65);
	for (auto &x : a) 
	{
		cin >> x;
		for (int i=59; ~i; --i) if (x>>i&1) num[i]++;
	}
	int ans = 0;
	for (auto x : a)
	{
		int sm1 = 0, sm2 = 0;
		for (int i=59; ~i; --i) if (x>>i&1) 
			sm1 = (sm1 + (1ll<<i)%p*num[i]%p)%p;
		for (int i=59; ~i; --i) 
			sm2 = (sm2 + (1ll<<i)%p*((x>>i&1)?n:num[i])%p)%p;
		ans = (ans + 1ll*sm1*sm2%p)%p;
	}
	cout << ans << "\n";
}