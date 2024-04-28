/// Name: mex
/// Guarantee: struct mex{
    
struct mex{
    set<int> base;
    mex(int n){
        repab(i,1,n+1) base.insert(i);
    }
    void add(int x){
        base.erase(x);
    }
    void remove(int x){
        base.insert(x);
    }
    int get(){
        return *base.begin();
    }
};
struct node_v{
    int sum;
    bool lazyreset,lazyall;
    bool lazyinvert;
    node_v() {
        lazyreset=lazyall=false;
        lazyinvert=false;
        sum=0;
    }
    void reset(int left,int right){
        lazyreset=true;
        lazyall=false;
        lazyinvert=false;
        sum=0;
    }
    void set(int left,int right){
        lazyall=true;
        sum=get_range(left,right);
        lazyreset=false;
        lazyinvert=false;
    }
    void invert(int left,int right){
        if(lazyall) {reset(left,right);return;}
        if(lazyreset) {set(left,right);return;}
        if(lazyinvert) {
            sum=get_range(left,right)-sum;
            lazyinvert=false;
            return;
        }
        lazyinvert=true;
        sum=get_range(left,right)-sum;
        lazyreset=false;
        lazyall=false;
    }
    int get_range(int left,int right){
        return right-left+1;
    }
    
    bool is_full(int left,int right){
        return get_range(left,right)==sum;
    }
};
struct mex_trie{
    vector<node_v> value; 
    map <ll,int> id;
    map <int,ll> invid;
    int lf,rt;
    mex_trie(vector<ll> tocompress){
        set<ll> toc;
        iter(x,tocompress) toc.insert(x);
        vector<ll> to(toc.begin(),toc.end());
        value.resize(4*sz(to));
        rep(i,sz(to)) {
            invid[i]=to[i];
            id[to[i]]=i;
        } 
        //error(id);
        lf=0;rt=sz(to)-1;
    }
    
    void push(int id,int left,int right){
        
        if(left!=right){
           
            ll t = (left + right) / 2;
            if(value[id].lazyall) {
                value[2*id].set(left,t);
                value[2*id+1].set(t+1,right);
            }
            if(value[id].lazyreset) {
                value[2*id].reset(left,t);
                value[2*id+1].reset(t+1,right);
            }
            if(value[id].lazyinvert) {
                value[2*id].invert(left,t);
                value[2*id+1].invert(t+1,right);
            }
        }
        value[id].lazyall=false;
        value[id].lazyreset=false;
        value[id].lazyinvert=false;
    }
    void add_all(ll lq, ll rq){
        return add_all(1,lf,rt,0,id[lq],id[rq]);
    }
    
    
    void add_all(int id, int left,int right, int depth,int lq, int rq){
        if (lq <= left && right <= rq){
            value[id].set(left,right);
            return ;
        }
        if (max(left, lq) > min(right, rq))
            return ;
        push(id,left,right);
        int t = (left + right) / 2;

        add_all(2*id,left,t,depth+1,lq, rq) ;
        add_all(2*id+1,t+1,right,depth+1,lq, rq);
        value[id].sum=value[2*id].sum+value[2*id+1].sum;
        //error(left,right,value[id].sum);
    }

    void remove_all(ll lq, ll rq){
        return remove_all(1,lf,rt,0,id[lq],id[rq]);
    }
    void remove_all(int id, int left,int right, int depth,int lq, int rq){
        if (lq <= left && right <= rq){
            value[id].reset(left,right);
            return ;
        }
        if (max(left, lq) > min(right, rq))
            return ;
        push(id,left,right);
    
        int t = (left + right) / 2;
         remove_all(2*id,left,t,depth+1,lq, rq) ;
         remove_all(2*id+1,t+1,right,depth+1,lq, rq);
         value[id].sum=value[2*id].sum+value[2*id+1].sum;
    }
    
    void invert_all(ll lq, ll rq){
        return invert_all(1,lf,rt,0,id[lq],id[rq]);
    }
    void invert_all(int id,int left,int right, int depth,int lq, int rq){
        if (lq <= left && right <= rq){
            value[id].invert(left,right);
            return ;
        }
        if (max(left, lq) > min(right, rq))
            return ;
        push(id,left,right);
    
        int t = (left + right) / 2; 
        invert_all(2*id,left,t,depth+1,lq, rq) ;
        invert_all(2*id+1,t+1,right,depth+1,lq, rq);
        value[id].sum=value[2*id].sum+value[2*id+1].sum;
    }
    ll get_mex(){
        return invid[get_mex(1,lf,rt,0)];
    }
    int get_mex(int id,int left,int right,int depth){
        if(left==right) return left;
        push(id,left,right);
        int t = (left + right) / 2;
        if(value[2*id].is_full(left,t)) return get_mex(2*id+1,t+1,right,depth+1);
        return get_mex(2*id,left,t,depth+1);
    }
    ll get_mex_with_xor(ll x){
        return invid[get_mex_with_xor(1,lf,rt,0,x)];
    }
    int get_mex_with_xor(int id, int left,int right,int depth, ll x){
        if(left==right) return left;
        push(id,left,right);
        ll t = (left + right) / 2;
        if((x&(1ll<<depth))==0){
            if(value[2*id].is_full(left,t)) return get_mex_with_xor(2*id+1,t+1,right,depth+1,x);
            return get_mex_with_xor(2*id,left,t,depth+1,x);
        }else {
            if(value[2*id+1].is_full(t+1,right)) return get_mex_with_xor(2*id,left,t,depth+1,x);
               return get_mex_with_xor(2*id+1,t+1,right,depth+1,x);
        }
    }
};