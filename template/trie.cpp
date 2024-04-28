/// Name: trie
/// Guarantee: class tree{
class tree{
    public:
    int leaves;
    tree* left,*right;
    tree(){leaves=0;}
};
tree* root;
tree store[MX];
int storei=0;
tree* insert(tree * r,int i,string & s){
    if(r==NULL) r= &store[storei++];
    if(i==sz(s)){
        r->leaves++;
        return r;
    } 
    assert(r!=NULL);
    if(s[i]=='0') r->left=insert(r->left,i+1,s);
    else r->right=insert(r->right,i+1,s);
    r->leaves++;
   // error(r->leaves);
    return r;
}
tree* erase(tree * r,int i,string & s){
    if(i==sz(s)){
        r->leaves--;
        return r;
    } 
    if(s[i]=='0') r->left=erase(r->left,i+1,s);
    else r->right=erase(r->right,i+1,s);
    r->leaves--;
    return r;
}
ll findmin(ll x){
    //error(x,root->leaves);
    string s = bitset<52>(x).to_string();
    tree * p=root;
    if(p->leaves==0) return LLONG_MAX;
    ll ans=0;
    rep(i,sz(s)){
        assert(p!=NULL);
        //error(ans,p->leaves);
        ans*=2;
        if(s[i]=='0' && p->left!=NULL && p->left->leaves!=0) p=p->left;
        else if(s[i]=='1' &&  p->right!=NULL && p->right->leaves!=0) p=p->right,ans++;
        else if(p->left!=NULL && p->left->leaves!=0) p=p->left;
        else p=p->right,ans++;
    }
   // error(ans);
    return ans^x;
}
string getbinary(ll x){
    return bitset<52>(x).to_string();
}