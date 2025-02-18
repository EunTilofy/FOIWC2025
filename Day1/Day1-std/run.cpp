#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5+10;

int n, m;
ll d[N][4];
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
vector<pair<int,int>> G[N];

int main()
{
    freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for (int i=1; i<=n; ++i) d[i][0] = d[i][1] = d[i][2] = d[i][3] = INF64;
	for (int i=1; i<=m; ++i)
	{
		int x, y, z;
		cin >> x >> y >> z;
		G[x].push_back({y, z});
		G[y].push_back({x, z});
	}
	priority_queue<tuple<ll, int, int>> q;
	q.push({0, 1, 0}); d[1][0] = 0;
	while (!q.empty())
	{
		auto [D, x, t] = q.top(); D = -D;
		q.pop();
		for (auto [y, w] : G[x])
		{
			// mult 2
			if (t % 2 == 0 && d[y][t+1] > D + w*2ll)
			{
				d[y][t+1] = D + w*2ll;
				q.push({-d[y][t+1], y, t+1});
			}
			// to 0
			if (t < 2 && d[y][t+2] > D)
			{
				d[y][t+2] = D;
				q.push({-d[y][t+2], y, t+2});
			}
			// normal
			if (d[y][t] > D + w)
			{
				d[y][t] = D + w;
				q.push({-d[y][t], y, t});
			}
		}
	}
	for (int i=1; i<=n; ++i)
	{
		cout << min({d[i][0], d[i][1], d[i][3]}) << " ";
	}
}