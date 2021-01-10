/*
ID: georgej2
LANG: C++
TASK: wormhole
*/
#include <bits/stdc++.h>
using namespace std;
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
int ans=0;
int adj[13];
bool vis[13];
p2 ax[13];
int pairs[13];
bool travel(int i,int n,bool v[13]){
    //cout<<"at "<<i<<" ";
    if(v[i]) return true;
    v[i]=true;
    i=pairs[i];
    //cout<<"to pair "<<i<<" ";
    i=adj[i];
    //cout<<"to next "<<i<<" ";
    if(i==0) return false;
    return travel(i,n,v);
}
bool check(int n,int a[13]){
    rep(i,n) pairs[a[i]]=a[i^1];
    //cout<<endl<<"check start:";
    //rep(i,n) cout<<pairs[i+1]<<" ";
    //cout<<endl;
    rep(i,n){
        rep(j,n) vis[j+1]=false;
        //cout<<endl<<"travel: ";
        //vis[i]=true;
        if(travel(i+1,n,vis)) return true;
    }
    return false;
}

void permute(int n,int i,int a[13]){
    if(i==n){
        if(check(n,a)) ans++;
    }else {
        reps(ii,i+1,n){
            swap(a[i+1],a[ii]);
            permute(n,i+2,a);
            swap(a[i+1],a[ii]);
        }
    }
}
int main() {
    ofstream cout ("wormhole.out");
    ifstream cin ("wormhole.in");
    int n;
    cin>>n;
    
    rep(i,n) cin>>ax[i].fi>>ax[i].se;
    rep(i,n){
        int f=-1;
        rep(j,n){
            if(j!=i){
                if(ax[j].fi>ax[i].fi && ax[j].se==ax[i].se && f==-1) f=j;
                else if(ax[j].fi>ax[i].fi && ax[j].se==ax[i].se && ax[f].fi>ax[j].fi) f=j;
            }
        }
        adj[i+1]=f+1;
    }
    int b[13];
    rep(i,n) b[i]=i+1;
    permute(n,0,b);
    cout<<ans<<endl;
    return 0;
}

