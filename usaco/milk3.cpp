/*
ID: georgej2
LANG: C++
TASK: milk3
*/
#define submit 0
#define task "milk3"
#define input(a,b) a#b
#define input_file input(task,.in)
#define output_file input(task,.out) 
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
const int maxN=1e3;
v(int) lists;
map<p3,bool> mp;
int aa,bb,cc;
p2 pour(int a,int b,int bx){
    int x=min(a,bx-b);
    a-=x;b+=x;
    return mk(a,b);
}
void recurse(int a,int b,int c){
    if(mp[mk(mk(a,b),c)]) return;
    mp[mk(mk(a,b),c)]=true;
    auto p=pour(a,b,bb);
    recurse(p.fi,p.se,c);
    p=pour(a,c,cc);
    recurse(p.fi,b,p.se);
    p=pour(b,a,aa);
    recurse(p.se,p.fi,c);
    p=pour(b,c,cc);
    recurse(a,p.fi,p.se);
    p=pour(c,b,bb);
    recurse(a,p.se,p.fi);
    p=pour(c,a,aa);
    recurse(p.se,b,p.fi);
    
}
int main() {
    #ifdef submit
        ofstream cout (output_file);
        ifstream cin (input_file);
    #endif
    
    cin>>aa>>bb>>cc;
    recurse(0,0,cc);
    for(auto x:mp) if(x.fi.fi.fi==0) lists.pb(x.fi.se); 
    sort(lists.begin(),lists.end());
    cout<<lists[0];
    reps(i,1,lists.size()) cout<<" "<<lists[i];
    cout<<endl;
    return 0;
}

