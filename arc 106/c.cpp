#include <atcoder/modint>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
using mint = modint998244353;
#define lli long long int
#define llu unsigned long long int
//#define sa(a,n,t) for(int ii=0;ii<n;ii++) scanf("%"#t"",&(a)[ii])
#define sa(a,n) rep(ii,n) cin>>a[ii];
#define rep(i,n) for(int i=0;i<n;i++) 
#define reps(i,a,n) for(int i=a;i<n;i++) 
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define rreps(i,a,n) for(int i=n-1;i>=a;i--)
#define validl(i,a,b) ((i>=a)&&(i<=b))?1:0
#define validmat(x,y,a,b,c,d) (validl(x,a,b) && validl(y,a,b))?1:0
#define validmn(x,y,m,n) validmat(x,y,0,m,0,n)
#define valid(i,n) validl(i,0,n)
#define v(t) vector<t>
#define vv(t) vector<vector<t> >
#define mk make_pair
#define pb push_back
#define pa(a,n,t)  for(int i=0;i<n;i++) printf("%"#t"",a[i])
#define p2 pair<int,int>
#define p3 pair<p2,int>
#define fi first
#define se second
#define sd(a) scanf("%d",&a)
#define sl(a) scanf("%lld",&a)
#define pl(a) printf("%lld",a)
#define pd(a) printf("%d",a)
#define sf(a) scanf("%lf",&a)
#define pf(a) printf("%lf",a)
#define nline printf("\n")
#define ss(a) scanf("%s",a)
#define ps(a) printf("%s",a)
#define sc(a) scanf("%c",&a)
#define pc(a) printf("%c",&a)
#define mf(m,f) m.find(f)!=m.end()
#define pp3(m) cout<<m.fi.fi<<" "<<m.fi.se<<" "<<m.se<<" "
#define pp2(m) cout<<m.fi<<" "<<m.se<<" "
#define debug 0
const int maxk =301;
const int maxN=2e5+1;
mint v[maxk][maxk];
mint s[maxk]={0},ans[maxk]={0};
v(mint) fact(maxN),ifact(maxN);

mint comb(int n,int m){
    return fact[n]*ifact[n-m]*ifact[m];
}
void init(){
    //mint::set_mod(1e9+7);
    fact[0]=1;
    reps(i,1,maxN) fact[i]=fact[i-1]*i;
    ifact[maxN-1]=fact[maxN-1].inv();//ex(fact[maxN-1].val(),MAX-2);
    rrep(i,maxN-1) ifact[i]=ifact[i+1]*(i+1);
    //ipow[0]=1;
    //reps(i,1,maxN) ipow[i]=ipow[i-1]*i2;
}
int a[maxN];
int main() {
    init();
    reps(i,1,maxk+1) rep(j,i+1) v[i][j]=comb(i,j);
    
    int n,k;
    cin>>n>>k;
   // reps(i,1,k+1) {rep(j,i+1) cout<<v[i][j].val()<<" "; cout<<endl;}
    sa(a,n);
    rep(j,k+1) s[j]=0,ans[j]=0;
    rep(i,n){
        mint x=1;
        rep(j,k+1){
            s[j]+=x;
            x=x*a[i];
        }
    }
    //rep(j,k+1) cout<<s[j].val()<<" ";
    reps(i,1,k+1) rep(j,i+1){
        ans[i]+=v[i][j]*s[j]*s[i-j];
    }
    rep(i,n){
        mint x=2*a[i];
        reps(j,1,k+1){
            ans[j]-=x;
            x=x*2*a[i];
        }
    }
    //mint i2=2;
    reps(j,1,k+1){
        ans[j]/=2;
    }
    reps(j,1,k+1) cout<<ans[j].val()<<endl;
    return 0;
}
