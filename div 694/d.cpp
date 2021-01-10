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
int a[300001];
  int c[1000001]={0};
  int d[1000001]={0};
int main()
{
  int t;
  sd(t);
  /*reps(i,1,1e6+1){
      int x=i;
        rreps(j,1,1001){
            if(x%(j*j)==0) {x=x/(j*j);break;}
        }
        d[i]=x;
    }*/
    reps(j,1,1001){
        reps(i,1,1e6){
            if(i*j*j>1e6) break;
            d[i*j*j]=i;
        }
    }
    //cout<<d[8]<<endl;
  rep(tt,t){
    int n,m;
    cin>>n;
    sa(a,n,d);
    
    cin>>m;
    //nline;
    int nps=0,ps=0;
    int mx=1,nmx=0;
    rep(i,n) a[i]=d[a[i]];
    //sort(a,a+n);
    rep(i,n) c[a[i]]++;
    rep(i,n){
        if(a[i]==1) {ps++;continue;}
        if(c[a[i]]<0) continue;
        int cc=c[a[i]];
        /*reps(j,1,1001){
            if(100e6/j/j<a[i]) break;
            if(a[i]*j*j>1e6) break;
            if(c[a[i]*j*j]>0) cc+=c[a[i]*j*j],c[a[i]*j*j]=-1;
        }*/
        c[a[i]]=-1;
            //cout<<cc<<" "<<a[i]<<endl;
            mx=max(mx,cc);
            if(cc%2==0) nps+=cc;
            else nmx=max(nmx,cc);
        }
    rep(i,m){
        lli x;
        cin>>x;
        if(x==0) cout<<max(ps,mx)<<endl;
        else cout<<max(ps+nps,nmx)<<endl;
    }
    rep(i,n) c[a[i]]=0;
  }
  return 0;
}
