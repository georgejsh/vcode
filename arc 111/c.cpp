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
const int maxN=2e+5;
int a[maxN],b[maxN],c[maxN],d[maxN];
int main()
{
  
  int n;
  cin>>n;
  sa(a,n,d);
  sa(b,n,d);
  rep(i,n){
      int x;
      cin>>x;
      c[x-1]=i;
      d[i]=x-1;
  }
  v(p2) ans;
  bool ok=true;
  for(int i=0;i<n;){
      if(c[i]==i) {i++;continue;}
      if(b[d[i]]>=a[i])  {ok=false;break;}
      //cout<<i<<" "<<c[i]<<" "<<d[i]<<" "<<endl;
      if(b[d[i]]>=a[c[i]]  && b[d[d[i]]]>=a[i]) {ok=false;break;}
      if(b[d[i]]<a[c[i]]) {
          int cc=c[i],dd=d[i];
          c[dd]=cc;
          d[cc]=dd;
          ans.pb(mk(i,cc));
          c[i]=d[i]=i;
          i++;
      }
      else{
          int cc=d[d[i]],dd=d[i];
          c[dd]=d[dd]=dd;
          c[cc]=i;
          d[i]=cc;
          ans.pb(mk(i,dd));
      }
  }
  if(ok) {
      cout<<ans.size()<<endl;
      for(auto x:ans) cout<<x.fi+1<<" "<<x.se+1<<endl;
  }else
  {
      cout<<-1<<endl;
  }
  
  return 0;
}
