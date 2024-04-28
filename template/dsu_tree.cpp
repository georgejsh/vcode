/// Name: dsu_tree
/// Guarantee: void dfs_size(int v, int p) {
vector<bool> big;
vi szs;
vector<vi> g;

void dfs_size(int v, int p) {
	szs[v] = 1;
	for (auto u : g[v]) {
		if (u != p) {
			dfs_size(u, v);
			szs[v] += szs[u];
		}
	}
}

void add(int v, int p){
    for(auto u: g[v])
        if(u != p && !big[u])
            add(u, v);
}

void remove(int v, int p){
    for(auto u: g[v])
        if(u != p && !big[u])
            remove(u, v);
}
void dfs(int v, int p, bool keep){
    int mx = -1, bigChild = -1;
    for(auto u : g[v])
       if(u != p && szs[u] > mx)
          mx = szs[u], bigChild = u;
    for(auto u : g[v])
        if(u != p && u != bigChild)
            dfs(u, v, 0);  // run a dfs on small childs and clear them from cnt
    if(bigChild != -1)
        dfs(bigChild, v, 1), big[bigChild] = 1,ans[v]=min(ans[v],ans[bigChild]);  // bigChild marked as big and not cleared from cnt
    //error(v,bigChild);
    add(v,p);
    //now cnt[c] is the number of vertices in subtree of vertex v that has color c. You can answer the queries easily.
    if(bigChild != -1)
        big[bigChild] = 0;
    if(keep == 0)
        remove(v, p);
}