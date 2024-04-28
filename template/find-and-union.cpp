/// Name: FU
/// Guarantee: struct FU {
struct FU {
    std::vector<int> f, siz;
    std::vector<int> id;
    FU() {}
    FU(int n) {
        init(n);
    }
    
    void init(int n) {
        f.resize(n);
        id.resize(n);
        std::iota(f.begin(), f.end(), 0);
        rep(i,n) id[i]=i;
        siz.assign(n, 1);
    }
    
    int leader(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    
    bool same(int x, int y) {
        return leader(x) == leader(y);
    }
    
    bool merge(int x, int y) {
        x = leader(x);
        y = leader(y);
        if (x == y) {
            return false;
        }
        if(rand() % 2) swap(x,y);
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    bool merge(int x, int y,function<int(int,int)> toid) {
        x = leader(x);
        y = leader(y);
        if (x == y) {
            return false;
        }
        if(rand() % 2) swap(x,y);
        siz[x] += siz[y];
        f[y] = x;
        id[x] =toid(id[x],id[y]);
        return true;
    }
    
    int size(int x) {
        return siz[leader(x)];
    }
};
