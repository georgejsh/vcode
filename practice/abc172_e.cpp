#include <atcoder/modint>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
using mint = modint;
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
const int maxN=5e5+1;
const int MAX=1e9+7;

unsigned long long int ex(unsigned long long int a,unsigned long long int n)
{
  if(n==0)
  return 1;
 if(n==1)
  return a;
  n=n%(MAX-1);
  unsigned long long int y=ex(a,n/2);
  if(n%2==1)
   return (a*((y*y)%MAX))%MAX;
  else
   return (y*y)%MAX;
}
v(mint) fact(maxN),ifact(maxN);
mint perm(int n,int m){
    return fact[n]*ifact[n-m];
}
mint comb(int n,int m){
    return fact[n]*ifact[n-m]*ifact[m];
}
void init(){
    mint::set_mod(1e9+7);
    fact[0]=1;
    reps(i,1,maxN) fact[i]=fact[i-1]*i;
    ifact[maxN-1]=ex(fact[maxN-1].val(),MAX-2);
    rrep(i,maxN-1) ifact[i]=ifact[i+1]*(i+1);
    //ipow[0]=1;
    //reps(i,1,maxN) ipow[i]=ipow[i-1]*i2;
}
mint getform(int n,int m,int i){
    return comb(n,i)*perm(m,i)*perm(m-i,n-i)*perm(m-i,n-i);
}

int main() {
    init();
    int n,m;
    cin>>n>>m;
    mint ans=0;
    mint k=1;
    rep(i,n+1){
       // cout<<getform(n,m,i).val()<<endl;
        ans+=k*getform(n,m,i);
        k=k*-1;
    }
    
    cout<<ans.val()<<endl;
    return 0;
}
