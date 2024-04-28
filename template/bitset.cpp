/// Name: bitset
/// Guarantee: class bits{

template<size_t SZ>
class bits{
    uint64_t b[(SZ+63)/64];
    int n=(SZ+63)/64;
    int initial_n=SZ;
    uint64_t all_set=0xFFFFFFFFFFFFFFFFull;
    public:
    bits(){
        reset();
    }
    bits& set(){
        for(int i=0;i<n;i++) b[i]=all_set;
        return *this;
    }
    
    bits& set(int pos){
        int pi=pos/64,i_in=pos%64;
        b[pi]|=(1ull<<i_in);
        return *this;
    }
    bits& reset(){
        for(int i=0;i<n;i++) b[i]=0;
        return *this;
    }
    bits& reset(int pos){
       int pi=pos/64,i_in=pos%64;
        b[pi]&=~(1ull<<i_in);
        return *this;
    }
    bits& flip(){
        for(int i=0;i<n;i++) b[i]=~b[i];
        return *this;
    }
    bits& flip(int pos){
        int pi=pos/64,i_in=pos%64;
        b[pi]&=(all_set ^ (1ull<<i_in));
        return *this;
    }
    int count(){
        int ans=0;
        for(int i=0;i<n;i++) ans+=__pop_countll(b[i]);
        return ans;
    }
    bool any(){
        return count()>0;
    }
    bool all(){
        return count()==initial_n;
    }
    bool test(int pos){
        int pi=pos/64,i_in=pos%64;
        return b[pi]&(1ull<<i_in);
    }
    bool operator[](int pos){
        return test(pos);
    }
    friend ostream& operator<<(ostream& os, const bits<SZ> &obj){
        for(int i=obj.n-1;i>=0;i--) for(int j=63;j>=0;j--) if(obj.b[i]&(1ull<<j)) os<<"1";else os<<"0";
        os<<"\n";
        return os;
    }
    bits operator<<(int sh){
        auto tmp=*this;
        int mv=sh/64;
        if(mv>0){
            for(int i=n-1;i>=mv;i--)
                tmp.b[i]=b[i-mv];
            for(int i=mv-1;i>=0;i--) tmp.b[i]=0;
            sh%=64;
        }
        uint64_t carry=0;
        uint64_t mask=~((1ull<<(64-sh))-1);
        for(int i=0;i<n;i++){
            auto nc=tmp.b[i]&mask;
            tmp.b[i]<<=sh;
            tmp.b[i]|=carry;
            carry=nc>>(64-sh);
        }
        //cout<<tmp;
        return tmp;
    }
    
    bits operator>>(int sh){
        auto tmp=*this;
        int mv=sh/64;
        if(mv>0){
            for(int i=0;i<n-mv;i++)
                tmp.b[i]=b[i+mv];
            for(int i=n-mv;i<n;i++) tmp.b[i]=0;
            sh%=64;
        }
        uint64_t carry=0;
        uint64_t mask=~((1ull<<(sh+1))-1);
        for(int i=n-1;i>=0;i--){
            auto nc=tmp.b[i]&mask;
            tmp.b[i]>>=sh;
            tmp.b[i]|=carry<<(64-sh);
            carry=nc;
        }
        //cout<<tmp;
        return tmp;
    }
    bits& set_first(int len){
        for(int i=0;i<len/64;i++) b[i]=all_set;
        //len=len%64;
        b[len/64]|=(1ull<<(len%64))-1;
        return *this;
    }
    bits& set_range(int l,int r){
        auto tmp=*this;
        tmp.reset();
        tmp.set_first(r-l+1);
        tmp=tmp<<l;
        (*this)|=tmp;
        return *this;
    }
    
    bits& reset_range(int l,int r){
        auto tmp=*this;
        tmp.reset();
        tmp.set_first(r-l+1);
        tmp=tmp<<l;
        tmp.flip();
        (*this)&=tmp;
        return *this;
    }
    
    bits& flip_range(int l,int r){
        auto tmp=*this;
        tmp.reset();
        tmp.set_first(r-l+1);
        tmp=tmp<<l;
        (*this)^=tmp;
        return *this;
    }
    friend void operator|=(bits<SZ> &objA,bits<SZ> &objB){
        for(int i=0;i<objA.n;i++) objA.b[i]|=objB.b[i];
        return ;
    }
    
    friend void operator&=(bits<SZ> &objA,bits<SZ> &objB){
        for(int i=0;i<objA.n;i++) objA.b[i]&=objB.b[i];
        return ;
    }
    
    friend void operator^=(bits<SZ> &objA,bits<SZ> &objB){
        for(int i=0;i<objA.n;i++) objA.b[i]^=objB.b[i];
        return ;
    }
    int msb(){
        int ans=0;
        for(int i=n-1;i>=0;i--) if(b[i]==0) ans+=64;else {
            ans+=__builtin_clzll(b[i]);
            break;
        }
        return ans;        
    }
    int lsb(){
        int ans=0;
        for(int i=0;i<n;i++) if(b[i]==0) ans+=64;else {
            ans+=__builtin_ctzll(b[i]);
            break;
        }
        return ans;
    }
 };

