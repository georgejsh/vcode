/// Name: power
/// Guarantee: long long binpow(long long a, long long b) {

long long binpow(long long a, long long b , long long m) {
    if (b == 0)
        return 1;
    long long res = binpow(a, b / 2,m);
    res=(res*res)%m;
    if (b % 2)
        return (res * a) %m;
    else
        return res ;
}

vi multiply(vi & res, vi& a, ll m){
    vi tmp(sz(res));
    #define m_s 2
    rep(i,m_s) rep(j,m_s) tmp[i*m_s+j]=0;
    rep(i,m_s) rep(j,m_s) rep(k,m_s){
        tmp[i*m_s+j]+= res[i*m_s+k] * a[k*m_s+j]%m;
        tmp[i*m_s+j]%=m;
    }
    return tmp;
}
vi id(vi &res){
    vi tmp(sz(res));
    #define m_s 2
    rep(i,m_s) tmp[i*m_s+i]=1;
    return tmp;
}
vi binpow(vi& a, ll b, ll m) {
    if (b == 0)
        return id(a);
    vi res = binpow(a, b / 2,m);
    res=multiply(res,res,m);
    if (b % 2)
        return multiply(res,a,m);
    else
        return res;
}
