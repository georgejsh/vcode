
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
int main() {
    lli n,l,t;
    cin>>n>>l;
    lli a[100001],b[100001];
    sa(a,n)
    sa(b,n);
    a[n]=b[n]=l+1;
    n++; 
    lli prev=0;
    rep(i,n) t=a[i],a[i]=a[i]-prev-1,prev=t;
    prev=0;
    rep(i,n) t=b[i],b[i]=b[i]-prev-1,prev=t;
   // rep(i,n) cout<<a[i]<<" ";
   // cout<<endl;
   // rep(i,n) cout<<b[i]<<" ";
    //cout<<endl;
    lli ans=0;
    int i,j;
    for( i=0,j=0;;){
        while(!b[j] && j<n) j++;
        while(!a[i] && i<n) i++;
        if(i==n ) break;
        if(j==n) break;
        lli la=0;
        int ii=i;
        while(la<b[j] && i<n) la+=a[i],i++;
        if(la!=b[j]) {cout<<-1<<endl;return 0;}
        //cout<<ii<<" "<<i<<" "<<j<<endl;
        ans+=max(j-ii,0)+max(i-1-j,0);
        j++;
    }
    if(i==n && j==n)
    cout<<ans<<endl;
    else {cout<<-1<<endl;return 0;}
    return 0;
}