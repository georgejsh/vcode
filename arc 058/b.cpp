#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define sa(a,n,t) for(int ii=0;ii<n;ii++) scanf("%"#t"",&(a)[ii])
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
/*v(int) adj[200001];
void dfs(int i,int p){
    rep(j,adj[i].size()){
        if(p!=adj[i][j])
            dfs(adj[i][j],i);
    }
}*/
const int n=2e5+2;
lli f[n];
lli invf[n];
const int MAX= 1e9+7;
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
lli ncr(int n,int r){
    return f[n]*invf[r]%MAX*invf[n-r]%MAX;
}
lli getpaths(int h,int w){
    return ncr(h+w,h);
}
int main()
{
  f[0]=1;
  reps(i,1,n) f[i]=f[i-1]*i%MAX; 
  invf[n-1] = ex(f[n-1],MAX-2);
  rrep(i,n-1) invf[i]=invf[i+1]*(i+1)%MAX;
  cout<<invf[2]<<endl;
  int h,w,a,b;
  cin>>h>>w>>a>>b;
  lli ans=getpaths(h-1,w-1);
  //cout<<ans<<endl;
  lli curr=0;
  rep(i,b){
      lli xx=(getpaths(h-a,i)-curr+MAX)%MAX*getpaths(a-1,w-i-1)%MAX;
      curr=(getpaths(h-a,i)+MAX)%MAX;
     // cout<<xx<<endl;
      ans=(ans-xx+MAX)%MAX;
  }
  cout<<ans<<endl;
  return 0;
}
