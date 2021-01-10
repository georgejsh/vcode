/*
ID: georgej2
LANG: C++
TASK: combo
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
bool check(int n,int i,int j,int k, int a[3]){
    bool ok=false;
    reps(ii,-2,3){
        if(i==(a[0]-1+ii+n)%n+1){ok=true;}
    }
    if(!ok) return false;
    ok=false;
    reps(ii,-2,3){
        if(j==(a[1]-1+ii+n)%n+1){ok=true;}
    }
    if(!ok) return false;
    ok=false;
    reps(ii,-2,3){
        if(k==(a[2]-1+ii+n)%n+1){ok=true;}
    }
    if(!ok) return false;
    return true;
}
int main() {
    ofstream cout ("combo.out");
    ifstream cin ("combo.in");
    int n;
    cin>>n;
    int a[2][3];
    rep(i,2) rep(j,3) cin>>a[i][j];
    int c=0;
    rep(i,n) rep(j,n) rep(k,n){
        if(check(n,i+1,j+1,k+1,a[0]) )  c++;
        else if(check(n,i+1,j+1,k+1,a[1]) )  c++;
    }
    cout<<c<<endl;
    return 0;
}

