/// Name: primes
/// Guarantee: struct primes{
struct primes{
    int lprime[MX];
    init(){
        lprime[0] = lprime[1] = 1;
        for (ll i = 2; i <= MX; i++) {
            if (!lprime[i]) {
                lprime[i]=i;
                for (ll j = i * i ; j <= MX; j += i)
                    if(!lprime[j]) lprime[j] = i;
            }
        }
    }
    vector<pair<ll, int>>  factor(int x){
        vector<int> fac;
        while(x!=1){
            auto y=lprime[x];
            while(x%y==0) fac.pb(y),x/=y;
        }
        sort(fac.begin(), fac.end());
        vector<pair<ll, int>> ans;
        for (auto x : fac) {
            if (ans.empty() || ans.back().first != x) {
                ans.emplace_back(x, 0);
            }
            ++ans.back().second;
        }
        return ans;
    }
    vector<int>  all_factor(int x){
        vector<int> fac;
        while(x!=1){
            auto y=lprime[x];
            while(x%y==0) fac.pb(y),x/=y;
        }
        sort(fac.begin(), fac.end());
        vector<int> p={1};
        iter(x,fac) {
            int n=p.size();
            rep(i,n) p.pb(p[i]*x);
        }
        
        sort( p.begin(), p.end() );
        p.erase( unique( p.begin(), p.end() ), p.end() );
        return p;
    }
}

