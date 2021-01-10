/*
ID: georgej2
LANG: C++
TASK: pprime
*/
//#define submit 0
#define task "pprime"
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
const int maxN=1e8+1;
bool isprime(lli n){
    for(lli i=2;i*i<=n;i++) if(n%i==0) return false;
    return true;
}
lli a,b;
int lb;
v(int) ans;
void addtoans(char s[20],int i,int f){
    if(f<=0) return;
    for(int j=f-1,k=0;j>i;j--,k++) s[j]=s[k];
      s[f]='\0';
      lli x;
      //cout<<s<<endl;
      sscanf(s,"%lld",&x);
      if(x>=a && x<=b && isprime(x)){
          ans.pb(x);
      }
}
void generatepalim(char s[20],int i,int n){
  if(i==n){

      addtoans(s,i-1,2*(i)-1);
        addtoans(s,i-1,2*(i));
  }else{
      addtoans(s,i-1,2*(i));
      addtoans(s,i-1,2*(i)-1);
      rep(j,10){
          s[i]='0'+j;
          generatepalim(s,i+1,n);
      }
  }

}
int main() {
    #ifdef submit
        ofstream cout (output_file);
        ifstream cin (input_file);
    #endif
    
    
    cin>>a>>b;
    char s[20];
    sprintf(s,"%lld",b);
    lb=strlen(s);
    generatepalim(s,0,ceil(lb/2.0));
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    //rep(i,ans.size()) cout<<ans[i]<<endl;
    return 0;
}

