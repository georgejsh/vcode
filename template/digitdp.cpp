/// Name: digit- dp
/// Guarantee: ll findnth(string &x,bool st,bool le,int prev,int i){
    
map<array(4),ll> mp;
// adjacent digits are not same
ll findnth(string &x,bool st,bool le,int prev,int i){
    if(sz(x)==i) return st;
    ll ans=0;
    if(mp.find({st,le,prev,i})!=mp.end()) return mp[{st,le,prev,i}]; 
    //error(x,st,le,prev,i);
    if(st && le){
        //started and less than already
        rep(j,10) if(j!=prev) ans+=findnth(x,st,le,j,i+1); 
    }else if(st && !le){
        //started but equal
        rep(j,10) if(j!=prev) {
            if(x[i]-'0'>j) ans+=findnth(x,st,true,j,i+1);
            else if(x[i]-'0'==j) ans+=findnth(x,st,false,j,i+1);
        }
    }else if(!st && le){
        // not started but equal - deals the less digit number cases
        rep(j,10)
            ans+=findnth(x,j!=0,true,j,i+1);
    }else{
        // not started and equal - deals starting digit case.
        rep(j,10){
            if(x[i]-'0'>j) ans+=findnth(x,j!=0,true,j,i+1);
            else if(x[i]-'0'==j) ans+=findnth(x,j!=0,false,j,i+1);
        }
    }
    mp[{st,le,prev,i}]=ans;
    return ans;
} 
ll nth(ll x){
    mp.clear();
    auto t=to_string(x);
    return findnth(t,false,false,0,0);
}