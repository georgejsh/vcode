/// Name: rollhash
/// Guarantee: vi compute_hash1(string const& s) {
ll mod1=1e9 + 9;
ll mod2=1e9+7;
ll p1=31;
ll p2=41;
ll p3=37;

vi compute_hash1(string const& s) {
    ll p = 31;
    ll m = 1e9 + 9;
    ll hash_value = 0;
    ll p_pow = 1;
    vi res;
    res.pb(hash_value);
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
        res.pb(hash_value);
    }
    return res;
}
vi compute_hash2(string const& s) {
    ll p = 41;
    ll m = 1e9 + 7;
    ll hash_value = 0;
    ll p_pow = 1;
    vi res;
    res.pb(hash_value);
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
        res.pb(hash_value);
    }
    return res;
}
vi compute_hash3(string const& s) {
    ll p = 37;
    ll m = 1e9 + 7;
    ll hash_value = 0;
    ll p_pow = 1;
    vi res;
    res.pb(hash_value);
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
        res.pb(hash_value);
    }
    return res;
}
ll getsub(vi &hash,int from,int to,ll mod,vi &inv){
    //error(to,from);
    if(to<from) return 0;
    return ((((hash[to+1]-hash[from]+mod)%mod)*inv[from+1])%mod);
}
vi inv1,inv2,inv3;
void init(){
    ll p1inv=838709685;
    inv1.pb(1);
    rep(i,MX) inv1.pb(inv1[sz(inv1)-1]*p1inv%mod1);
    ll p2inv=658536590;
    inv2.pb(1);
    //error(inv1);
    rep(i,MX) inv2.pb(inv2[sz(inv2)-1]*p2inv%mod2);
    ll p3inv=621621626;
    
    inv3.pb(1);
    rep(i,MX) inv3.pb(inv3[sz(inv3)-1]*p3inv%mod2);
}