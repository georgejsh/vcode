/// Name: ternary
/// Guarantee: double ternary_search(double l, double r) {
double ternary_search(double l, double r) {
    double eps = 1e-9;              //set the error limit here
    while (r - l > eps) {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        double f1 = f(m1);      //evaluates the function at m1
        double f2 = f(m2);      //evaluates the function at m2
        if (f1 < f2)            
            l = m1;
        else
            r = m2;
    }
    return f(l);                    //return the maximum of f(x) in [l, r]
}


ll f(vi &a,ll b,ll l){
    if(l>b) return a[l];
    return b-l+a[l];
}
ll ternary_search(vi &a,ll b,ll l, ll r) {
    ll eps = 3;              //set the error limit here
    while (r - l > eps) {
        ll m1 = l + (r - l) / 3;
        ll m2 = r - (r - l) / 3;
        ll f1 = f(a,b,m1);      //evaluates the function at m1
        ll f2 = f(a,b,m2);      //evaluates the function at m2
        //error(m1,m2,f1,f2);
        if (f1 > f2)                    //find minimum
            l = m1;
        else
            r = m2;
    }

    return min({f(a,b,l),f(a,b,l+1),f(a,b,r)});                    //return the minimum of f(x) in [l, r]
}