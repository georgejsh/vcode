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
unsigned long long int ex(unsigned long long int a,unsigned long long int n,unsigned long long int  m)
{
    //a=
  if(n==0)
  return 1;
 if(n==1)
  return a%m;
  //n=n%(m-1);
  unsigned long long int y=ex(a,n/2,m);
  if(n%2==1)
   return (a*((y*y)%m))%m;
  else
   return (y*y)%m;
}
int main()
{
  lli n,m;
  cin>>n>>m;
  lli mod1=ex(10,n,m*m);
 // lli mod2=ex(10,n,m);
  //cout<<mod1<<" "<<mod2<<endl;
  cout<<mod1/m<<endl;
 // rep(i,m){
  //    if(i*m==(mod1-mod2+m*m)%(m*m)) {cout<<i<<endl;break;}
 // }
  return 0;
}
