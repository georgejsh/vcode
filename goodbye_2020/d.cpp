#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

const int N = 100'007;

int n;
int w[N];
int deg[N];

void solve() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &w[i]);
		deg[i] = 0;
	}
	
	for(int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d %d", &u, &v);
		deg[u]++; deg[v]++;
	}
	
	LL ans = 0;
	vector <int> to_sort;

	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j < deg[i]; ++j)
			to_sort.push_back(w[i]);
		ans += w[i];
	}
	
	sort(to_sort.begin(), to_sort.end());
	reverse(to_sort.begin(), to_sort.end());
	
	printf("%lld ", ans);
	for(auto &v: to_sort) {
		ans += v;
		printf("%lld ", ans);
	}
	
	printf("%lld\n", ans);
}

int main() {
	int cases;
	scanf("%d", &cases);
	
	while(cases--)
		solve();
	return 0;
}