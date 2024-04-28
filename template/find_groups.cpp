/// Name: find grouped characters
/// Guarantee: vector<pair<char,int>> findgroups(string s){
vector<pair<char,int>> findgroups(string s){
    pair<char,int> p;
    p.fi=s[0];
    p.se=1;
    vector<pair<char,int>> res;
    res.pb(p);
    repab(i,1,sz(s)){
        auto &x=res.back();
        if(x.fi==s[i]) x.se++;
        else {
            p.fi=s[i];
            p.se=1;
            res.pb(p);
        }
    }
    //res.pb(p);
    return res;
}

vector<pair<int,int>> findgroups(vi s){
    pair<int,int> p;
    p.fi=s[0];
    p.se=1;
    vector<pair<int,int>> res;
    res.pb(p);
    repab(i,1,sz(s)){
        auto &x=res.back();
        if(x.fi==s[i]) x.se++;
        else {
            p.fi=s[i];
            p.se=1;
            res.pb(p);
        }
    }
    //res.pb(p);
    return res;

}

int sumofdigits(ll x){
    ll sod=0;
    while(x){
        sod+=x%10;
        x/=10;
    }
    return sod;
}