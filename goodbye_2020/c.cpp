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
v(int) adj[200001];
int w[100001];
//int par[100001];
//int childc[100001];
int degree[100001];
priority_queue<p2,vector<p2>,less<p2> > pq;
void dfs(int i,int p){
    int v=0;
    rep(j,adj[i].size()){
        if(p!=adj[i][j])
            dfs(adj[i][j],i),v++;
    }
    //childc[i]=v;
    //par[i]=p;
    if(v==0) pq.push(mk(w[p],p));
}

int main()
{
  int t;
  sd(t);
  rep(tt,t){
    //cout<<"Case #"<<tt+1<<": ";
    int n;
    sd(n);
    sa(w,n,d);
    rep(i,n) adj[i].clear(),degree[i]=0;
    while(!pq.empty())pq.pop();
    rep(i,n-1){
        int p,q;
        cin>>p>>q;p--;q--;
        adj[p].pb(q);
        adj[q].pb(p);
        degree[p]++;
        degree[q]++;
    }
    int y=0;
    rep(i,n) if(degree[i]>1) {y=i;}
    dfs(y,-1);
    llu sum=0;
    rep(i,n) sum+=w[i];
    cout<<sum<<" ";
    rep(i,n-2){
        auto x=pq.top();
        pq.pop();
        while(degree[x.se]==1) {
            x=pq.top();
            pq.pop();
        }
        sum+=x.fi;
        degree[x.se]--;
        if(degree[x.se]==1)
        rep(j,adj[x.se].size()){
            if(degree[adj[x.se][j]]!=1){ 
                pq.push(mk(w[adj[x.se][j]],adj[x.se][j]));
                break;
            }
               
        }
        //pp2(x); cout<<childc[x.se]<<" aaa ";
        //if(!childc[x.se] && par[x.se]!=-1) pq.push(mk(w[par[x.se]],par[x.se]));

        cout<<sum<<" ";
    }
   /* while(!pq.empty()){
        auto x=pq.top();
        pq.pop();
        pp2(x);
    }*/
    nline;
  }
  return 0;
}
