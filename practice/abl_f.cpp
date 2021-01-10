#include <atcoder/modint>
#include <atcoder/convolution>
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
const int maxN=10e4+1;
v(modint998244353) fact(maxN),ifact(maxN),ipow(maxN);
vector<v(modint998244353) > poly;
modint998244353 pairc(int n){
    return fact[2*n]*ifact[n]*ipow[n];
}
modint998244353 getv(int n,int i){
    return fact[n]*ifact[2*i]*ifact[n-2*i]*pairc(i);
}
#define MAX 998244353
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
int main() {
    //int a[maxN];
    modint998244353 i2=(MAX+1)/2;
    fact[0]=1;
    reps(i,1,maxN) fact[i]=fact[i-1]*i;
    ifact[maxN-1]=ex(fact[maxN-1].val(),MAX-2);
    rrep(i,maxN-1) ifact[i]=ifact[i+1]*(i+1);
    ipow[0]=1;
    reps(i,1,maxN) ipow[i]=ipow[i-1]*i2;
   // cout<<ifact[2].val()<<endl;
   // cout<<ipow[maxN-1].val()<<endl; 
    int b[maxN]={0},x;
    priority_queue<p2,v(p2),greater<p2> > pq;
    int n;
    cin>>n;
    rep(i,2*n) cin>>x,b[x]++;
    rep(i,maxN){
        if(b[i]>1 ){
            v(modint998244353) tm(b[i]/2+1);
            for(int j=0;j<=b[i]/2;j++){
                if(!j) tm[j]=1;
                else tm[j]=getv(b[i],j);
            }
            poly.pb(tm);
            pq.push(mk(b[i]/2+1,poly.size()-1));
        }
    }
    while(pq.size()>1){
        auto p=pq.top();
        pq.pop();
        auto q=pq.top();
        pq.pop();
        auto x=convolution(poly[p.se],poly[q.se]);
        poly.pb(x);
        pq.push(mk(p.fi+q.fi,poly.size()-1));
    }
    if(pq.size()==0){
        cout<<pairc(n).val()<<endl;
        return 0;
    }
    auto xx=pq.top();
    modint998244353 ans=0;
    modint998244353 k=1;
    rep(i,poly[xx.se].size()){
       // cout<<poly[xx.se][i].val()<<" ";
        ans=ans+k*poly[xx.se][i]*pairc(n-i);
        k=k*-1;
    }
    //cout<<endl;
    cout<<ans.val()<<endl;
    return 0;
}
