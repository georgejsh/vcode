/*
ID: georgej2
LANG: C++
TASK: ariprog
*/
//#define submit 0
#define task "ariprog"
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
bool mp[5000001]={0};
int main() {
    #ifdef submit
        ofstream cout (output_file);
        ifstream cin (input_file);
    #endif
    int n,m;
    cin>>n>>m;
    //m=250;
    
    v(p2) seq;
    v(int) bisq;
    rep(i,m+1) reps(j,i,m+1){
       if( !mp[i*i+j*j]) bisq.pb(i*i+j*j);
        mp[i*i+j*j]=true;
    }
    
    sort(bisq.begin(),bisq.end());
    //rep(i,bisq.size()) cout<<bisq[i]<<" ";
    //cout<<bisq.size()<<endl;
    int c=0;
    rep(i,bisq.size()){
        reps(j,i+1,bisq.size()){
            int s=(bisq[i]+bisq[j]);
            //if(s%2!=0 ) continue;
            //if(! mp[s/2]) continue;
            //int d=s/2-min(bisq[i],bisq[j]);
            //if(d==0) continue;
            int d=bisq[j]-bisq[i];
            bool ok=true;
            int st=min(bisq[i],bisq[j]);
            rep(k,n){
                if(!mp[st+k*d]) {ok=false;break;}
            }
            if(ok) seq.pb(mk(d,st));
            //if(s%2==0 && mp[s/2]) seq.pb(mk(min(bisq[i],bisq[j]),s/2-min(bisq[i],bisq[j])));
        }
    }
    if(seq.size()==0) cout<<"NONE"<<endl;
    //sort(seq.begin(),seq.end());
    cout<<seq.size()<<endl;
    //rep(i,seq.size()) cout<<seq[i].se<<" "<<seq[i].fi<<endl;
    return 0;
}

