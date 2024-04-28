
/// Name: get_largest_k
/// Guarantee: struct k_large{

template<size_t T>
struct k_large{
    multiset<array<ll,T>> top,bottom;
    int keeptop;
    int keepbottom;
    ll sum_top,sum_bottom;
    // k_top - number of top k elements to keep
    // -1 for median
    // kbot - number of other than top elements to keep
    k_large(int ktop,int kbot=-1){
        keeptop=ktop;
        sum_top=sum_bottom=0;
       keepbottom=kbot;
       if(keeptop==-1) keepbottom=-1;
    }
    
    void balance(){
        int k=keeptop;
        if(keeptop==-1) k=(sz(top)+sz(bottom)+1)/2;
        while(sz(top)>k) {
            sum_top-=(*top.begin())[0];
            sum_bottom+=(*top.begin())[0];
            bottom.insert(*top.begin());
            top.erase(top.begin());
        }
        while(sz(bottom) && sz(top)<k) {
            sum_top+=(*bottom.rbegin())[0];
            sum_bottom-=(*bottom.rbegin())[0];
            top.insert(*bottom.rbegin());
            bottom.erase(bottom.find(*bottom.rbegin()));
        }
        if(keepbottom!=-1) 
        while(sz(bottom)>keepbottom) {
            sum_bottom-=(*bottom.rbegin())[0];
            bottom.erase(bottom.find(*bottom.rbegin()));
        }
    }
    void add(array<ll,T> x){
        top.insert(x);
        sum_top+=x[0];
        balance();
    }
    void remove(array<ll,T> x){
        if(top.find(x)!=top.end()) top.erase(top.find(x)),sum_top-=x[0];
        else bottom.erase(bottom.find(x)),sum_bottom-=x[0];
        balance();
    }
    ll sumtop(){
        return sum_top;
    }
    ll sumbottom(){
        return sum_bottom;
    }
    ll getmedian(){
        return top.begin();
    }
    ll getlargest(){
        return top.rbegin();
    }
};