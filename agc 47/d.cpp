
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
#define mx 1000000007ll
int p[1<<19];
lli n[1<<19]={0};
lli answer=0;
lli findtop(int l,int i){
    lli ans=1;
    while(l>=1)
        ans=(ans*i)%mx,i=i/2,l--;
    return ans;
}
void dotop(int i,lli ans){
    //lli ans=1;
    while(i!=0){
        ans=(ans*i)%mx;
        n[i]=(n[i]+ans)%mx;
     //cout<<"Stored "<<i<<" "<<n[i]<<endl;
        i=i/2;
    }
}
void findtouch(int i,lli ans){
    //lli ans=1;
    lli tillnw=0;
    while(i!=0){
        if(n[i] ){
            //cout<<(((n[i]-i*tillnw%mx+mx)%mx)*ans)%mx<<" "; 
            answer=(answer+ (((n[i]-i*tillnw%mx+mx)%mx)*ans)%mx)%mx;
            // cout<<"Found "<<i<<" "<<ans<<endl; 
             tillnw=n[i];
             }
        ans=(ans*i)%mx;
        //n[i]=(n[i]+ans)%mx;
        i=i/2;
    }
}

void cleartop(int i){
    //lli ans=1;
    while(i!=0){
        n[i]=0;
       // cout<<"Cleared "<<i<<" "<<n[i]<<endl;
        i=i/2;
    }
}
int h;
void traverse(int hh,int l,int r){
    if(l==r) return;
    int mid=(l+r)/2;
    int xx=1<<(h-1);
    reps(i,l,mid+1){
        lli x=findtop(hh,xx+i);
      //  cout<<xx+i<<":"<<x<<" ,";
        dotop(xx+p[i],x);
    }
    reps(i,mid+1,r+1)
    {
        lli x=findtop(hh-1,xx+i);
      //  cout<<xx+i<<":"<<x<<" ,";
        findtouch(xx+p[i],x);
    }
    reps(i,l,mid+1){
        cleartop(xx+p[i]);
    }
    traverse(hh-1,l,mid);
    traverse(hh-1,mid+1,r);
}

int main() {
    cin>>h;
    rep(i,(1<<(h-1)))
        cin>>p[i],p[i]--;
    traverse(h,0,(1<<(h-1))-1);
    cout<<answer<<endl;
    return 0;
}
