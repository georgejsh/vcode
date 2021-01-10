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
v(int) adj[400001];
bool vis[400001]={0};
bool extra=false;
int dfs(int i,int p){
    if(vis[i]) return 0;
    int s=1;
    vis[i]=true;
    //cout<<i<<endl;
    rep(j,adj[i].size()){
        if(p!=adj[i][j]){
            if(vis[adj[i][j]]) extra=true;
            s+=dfs(adj[i][j],i);
        }
            
    }
    return s;
}
int main()
{
  int n;
  cin>>n;
  rep(i,n){
      int a,b;
      cin>>a>>b;
      a--,b--;
      adj[a].pb(b);
      adj[b].pb(a);
  }
  int ans=0;
  rep(i,4e5) {
      extra=false;
      if(!vis[i])
      ans+=dfs(i,-1)-1+extra;
  }
  cout<<ans<<endl;
  return 0;
}
