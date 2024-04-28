/// Name: topo_sort
/// Guarantee: void topological_sort() {

vector<vector<int>> adj; // adjacency list of graph
vector<bool> visited;
vector<int> topo;

void dfs(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u])
            dfs(u);
    }
    topo.push_back(v);
}

void topological_sort(int n) {
    visited.assign(n, false);
    topo.clear();
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
    reverse(topo.begin(), topo.end());
}

set<pi> ss;
unordered_map<ll,ll> mp;
vi adj[MX];
int n;

void rem(int x){
    //error(x,ss,mp);
    if(mp.find(x)==mp.end()) return;
    ss.erase(ss.find(mk(mp[x],x)));
    mp.erase(x);
    iter(y,adj[x]){
        int ch=y;
        if(mp.find(ch)==mp.end()) return;
        auto todel=ss.find(mk(mp[ch],ch));
        if(todel!=ss.end())
            ss.erase(todel);
        mp[ch]--;
        ss.insert(mk(mp[ch],ch));
    }
    
    //error(ss,mp);
}
void compute(){
    mp.clear();
    ss.clear();
    rep(i,n) iter(x,adj[i]) mp[x]++;
    rep(i,n) {
        ss.insert(mk(mp[i],i));
   }
}
set<int> short_deg_del(bool independent=true){
    
    set<ll> ans;
    while(sz(ss)){
        auto x=*ss.begin();
        //error(x);
        
        rem(x.se);
        if(independent){
            bool ok=true;
            iter(y,adj[x.se]){
                if(ans.find(y)!=ans.end()) ok=false;
            }
            if(ok){
                    ans.insert(x.se);
                    iter(y,adj[x.se])
                            rem(y);
            }
        }
        
        
    }
    return ans;
}