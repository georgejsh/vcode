#include <atcoder/maxflow>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
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
const int maxN=200001;
const int maxV=1e9;
int a[maxN];
int b[maxN];
int main() {
    int n,m;
    lli sa=0,sb=0;
    cin>>n>>m;
    rep(i,n) cin>>a[i],sa+=a[i];
    rep(i,n) cin>>b[i],sb+=b[i];
    mf_graph<lli> graph(n+2);
    int st=n,end=st+1;
    rep(i,m){
        int x,y;
        cin>>x>>y;
        x--;y--;
        graph.add_edge(x,y,maxV*1e6);
        graph.add_edge(y,x,maxV*1e6);
    }
    if(sa!=sb){
        cout<<"No"<<endl;
        return 0;
    }
    lli v=0;
    rep(i,n) {
        if(b[i]>a[i]){
            graph.add_edge(st,i,b[i]-a[i]);
           // graph.add_edge(i,st,b[i]-a[i]);
            v+=b[i]-a[i];
        }else if(b[i]<a[i]){
            graph.add_edge(i,end,a[i]-b[i]);
           // graph.add_edge(i,st,a[i]-b[i]);
        }
    }
    lli fl=graph.flow(st,end);
    if(fl!=v){
         cout<<"No"<<endl;
        return 0;
    }
    cout<<"Yes"<<endl;
    return 0;
}
