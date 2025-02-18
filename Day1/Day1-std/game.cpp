#include<bits/stdc++.h>
using namespace std;

const int N = 2003;
int n, a[N], f[N][N], g[N][N], s[N][N];

void print(int l, int r)
{
	if (l==r) return;
	print(g[l][r]+1, r);
	print(l, g[l][r]);
	cout << l << " ";
}

void solve()
{
	cin >> n;
	memset(f, 63, sizeof f);
	for (int i=1; i<=n; ++i)
		cin >> a[i], f[i][i] = 1, s[i][i] = a[i];
	for (int l=2; l<=n; ++l)
	{
		for (int i=1; i+l-1<=n; ++i)
		{
			int j=i+l-1;
			for (int k=i; k<j; ++k)
			{
				if (f[i][k]+f[k+1][j] < f[i][j])
					f[i][j] = f[i][k] + f[k+1][j];
				if (f[i][k]==1 && f[k+1][j]==1 && s[i][k]==s[k+1][j])
					f[i][j] = 1, g[i][j] = k, s[i][j] = s[i][k] + 1;
			}
		}
	}
	if(f[1][n]==1)
	{
		cout << "jiu shi xun la!\n";
		print(1, n);
		cout << '\n';
	}
	else
	{
		cout << "si le la!\n" << f[1][n] << '\n';
	}
}

int main()
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	
	ios::sync_with_stdio(0); cin.tie(0);
	
	int T; cin >> T;
	while (T--) solve();
}