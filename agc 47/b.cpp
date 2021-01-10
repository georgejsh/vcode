
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
struct node{
    struct node * ch[26]={0};
    int ends=0;
};
struct node* head;
void insert(string s){
    struct node* p=head;
    rrep(i,s.length()){
        if(p->ch[s[i]-'a']==NULL){
               p->ch[s[i]-'a'] = new struct node(); 
        }
        p=p->ch[s[i]-'a'];
    }
    p->ends++;
}
int traverse(string s){
    map<char,int> ss;
    rep(i,s.length()) ss[s[i]]++;
    struct node* p=head;
    int ans=0;
    rrep(i,s.length()){
        for(auto x:ss){
            if(x.se && p->ch[x.fi-'a']!=NULL) ans+=p->ch[x.fi-'a']->ends;
        }
        if(p->ch[s[i]-'a']==NULL) break;
        p=p->ch[s[i]-'a'];
        ss[s[i]]--;
    }
    return ans;
    //p->ends++;
}
int main() {
    head=new struct node();
    int n;
    cin>>n;
    lli ans=0;
    string s[200001];
    rep(i,n){
        //string s;
        cin>>s[i];
        //ans+=traverse(s);
        insert(s[i]);
    }
    rep(i,n)
    ans+=traverse(s[i]);
    cout<<ans-n<<endl;
    return 0;
}
