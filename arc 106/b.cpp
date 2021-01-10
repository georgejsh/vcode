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
int main() {
    int n,m;
    cin>>n>>m;
    if(n==1 && m==0){
        cout<<"1 2"<<endl;
        return 0;
    }
    if(m<0) {
        cout<<-1<<endl;
        return 0;
    }
    if(m>n-2) {
        cout<<-1<<endl;
        return 0;
    }
    int c=(n-2)-m;
    int c2=(n-1)-c;
    int x=1,y=1e6;
    cout<<x<<" "<<y<<endl;
    x++;
    rep(i,c2) {
        cout<<x<<" "<<x+1<<endl;
        x+=2;
    }
    x=y+1;
    rep(i,c){
        cout<<x<<" "<<x+1<<endl;
        x+=2;
    }
    return 0;
}
