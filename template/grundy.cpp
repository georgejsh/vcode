/// Name: grundy numbers
/// Guarantee: struct grundy{

template<typename T>
struct grundy{
    map<vector<T>,int> results;
    vector<function<vector<vector<T>>(vector<T>)>> moves;
    grundy(){}
    void add_moves(function<vector<vector<T>>(vector<T>)> m){
        moves.pb(m);
    }
    int get_mex(set<int> &s){
        int c=0;
        iter(y,s) if(y==c) c++;else break;
        return c;
    }
    int findans(vector<T> curr){
        if(results.find(curr)!=results.end()) return results[curr];
        set<int> ans;
        iter(x,moves){
            auto nex=x(curr);
            iter(y,nex){
                auto res=findans(y);
                //if(!res) {ans=true;return ans;}
                 ans.insert(res);
            }
        }
        results[curr]=get_mex(ans);
        return results[curr];
    }
    void recurse(int start,vector<T> curr,int val_start,int val_end,int array_size_start,int array_size_end){
        if(array_size_start<=start && start<=array_size_end){
           //error(curr);
            findans(curr);
        }
        if(start==array_size_end) return;
        repab(i,val_start,val_end+1){
            curr.pb(i);
            recurse(start+1,curr,val_start,val_end,array_size_start,array_size_end);
            curr.pop_back();
        }
    }
    void run(int val_start,int val_end,int array_size_start,int array_size_end){
        vector<T> tmp;
        recurse(0,tmp,val_start,val_end,array_size_start,array_size_end);
    }
    void print(bool print_zero=false){
        auto res=vector<pair<vector<T>,int>>(all(results));
        sort(all(res), [](const pair<vector<T>,int> & a, const pair<vector<T>,int> & b) -> bool
        { 
            if(a.fi.size()!=b.fi.size())
                return a.fi.size() < b.fi.size(); 
            return a.fi<b.fi;
        });

        iter(x,res){
         //   if(!print_zero) if(find(x.fi.begin(), x.fi.end(), 0) != x.fi.end()) continue;
            error(x.fi,x.se);
        }
    }
    bool check(function<bool(vector<T>)> sol,bool print_zero=false){
        iter(x,results){
         //   if(!print_zero) if(find(x.fi.begin(), x.fi.end(), 0) != x.fi.end()) continue;
            auto ans=sol(x.fi);
            if(x.se!=ans){
                error(x.fi,x.se,ans);
                return false;
            }
        }
        return true;
    }
    /*bool is_2(bool print_zero=false){
        iter(x,results){
         //   if(!print_zero) if(find(x.fi.begin(), x.fi.end(), 0) != x.fi.end()) continue;
            bool ans=false;
            iter(y,x.fi)
                ans^=findans({y});
            if(x.se!=ans){
                error(x.fi,x.se,ans);
                return false;
            }
        }
        return true;
    }*/
};

template<class T, size_t SZ>
struct grundy_gen:public grundy<array<T,SZ>>{
    
    void run(int val_start[SZ],int val_end[SZ],int array_size_start,int array_size_end){
        vector<array<T,SZ>> tmp;
        recurse(0,tmp,val_start,val_end,array_size_start,array_size_end);
    }
    void recurse_elem(int start,array<T,SZ> &curr,vector<array<T,SZ>> &all_e,int val_start[SZ],int val_end[SZ]){
        if(start==SZ){
            all_e.pb(curr);
            return;
        }
        repab(i,val_start[start],val_end[start]+1) {
            curr[start]=i;
            recurse_elem(start+1,curr,all_e,val_start,val_end);
        }
    }
    vector<array<T,SZ>> all_elem(int val_start[SZ],int val_end[SZ]){
        array<T,SZ> curr;
        vector<array<T,SZ>> all_e;
        recurse_elem(0,curr,all_e,val_start,val_end);
        return all_e;
    }
    void recurse(int start,vector<array<T,SZ>> &curr,int val_start[SZ],int val_end[SZ],int array_size_start,int array_size_end){
        if(array_size_start<=start && start<=array_size_end){
           //error(curr);
            this->findans(curr);
        }
        if(start==array_size_end) return;
        
        iter(y,all_elem(val_start,val_end)){
            curr.pb(y);
            recurse(start+1,curr,val_start,val_end,array_size_start,array_size_end);
            curr.pop_back();
        }

    }
    
};
template<typename T>
multiset<T>  to_multiset(vector<T> c){
    multiset<T> res;
    iter(x,c) res.insert(x);
    return res;
} 

vector<vector<int>> remove_1_from_1_bin(vector<int> curr){
    bool done=false;
    vector<vector<int>> res;
    rep(i,sz(curr)){
        if(curr[i]){
            curr[i]--;
            res.pb(curr);
            curr[i]++;
        }
    }
    return res;
}
template<size_t t>
vector<vector<int>> remove_t_from_1_bin(vector<int> curr){
    bool done=false;
    vector<vector<int>> res;
    rep(i,sz(curr)){
        if(curr[i]>=t){
            curr[i]-=t;
            res.pb(curr);
            curr[i]+=t;
        }
    }
    return res;
}
vector<vector<int>> remove_all_from_1_bin(vector<int> t){
    rep(i,sz(t)) if(t[i]){
        t[i]=0;
        return {t};
    }
    return {};
}
vector<vector<int>> remove_1_from_all_bin(vector<int> curr){
    bool ok=true;
    rep(i,sz(curr)){
        if(!curr[i]){
            ok=false;
        }
    }
    if(!ok) return {};
    rep(i,sz(curr)){
        curr[i]--;
    }
    return {curr};
}
vector<vector<int>> split_half_from_1_bin(vector<int> curr){
    bool done=false;
    vector<vector<int>> res;
    rep(i,sz(curr)){
        if(curr[i]>1){
            int x=curr[i];
            curr[i]=x/2;
            curr.pb((x+1)/2);
            res.pb(curr);
            curr.pop_back();
            curr[i]=x;
        }
    }
    return res;
}
vector<vector<int>> split_any_from_1_bin(vector<int> curr){
    bool done=false;
    vector<vector<int>> res;
    rep(i,sz(curr)){
        if(curr[i]>1){
            int x=curr[i];
            repab(j,1,x){
                curr[i]=j;
                curr.pb(x-j);
                res.pb(curr);
                curr.pop_back();
                curr[i]=x;    
            }
        }
    }
    return res;
}


bool sol(vector<int>  c){
    int ans=false;
    iter(x,c) ans^=(x%3);
    return ans!=0;
}
bool sol1(vector<int>  c){
    int ans=sz(c);
    iter(x,c) ans+=x;
    return ans%2==1;
}
template<size_t t>
vector<vector<array(2)>> split_1_bin(vector<array(2)> curr){
   vector<vector<array(2)>> res;
   rep(i,sz(curr)){
    if(curr[i][1] && curr[i][0]>=t){
        curr[i][0]-=t;
        curr[i][1]=0;
        res.pb(curr);
        curr[i][0]+=t;
        curr[i][1]=1;
    }else if(curr[i][0]>=t){
        int x=curr[i][0];
        repab(j,0,x+1-t){
            curr[i][0]=j;
            array(2) add={static_cast<long long>(x-t-j),0};
            curr.pb(add);
            res.pb(curr);
            curr.pop_back();
        }
        curr[i][0]=x;
    }
   } 
   //error(curr,res);
   return res;
}/*
void solve(){
    //grundy<int> g;
   grundy_gen<ll,2> gg;
   // g.add_moves(remove_1_from_1_bin);
    //g.add_moves(split_half_from_1_bin);
  //  g.add_moves(split_any_from_1_bin);
    //g.add_moves(remove_t_from_1_bin<2>);
    //g.add_moves(remove_all_from_1_bin);
   //g.add_moves(remove_1_from_all_bin);
  // g.run(1,5,1,4);
  //  g.print();
  //  cout<<g.is_2()<<"\n";
  //  error(g.check(sol1));
  //grundy<array(2)> gg;
  gg.add_moves(split_1_bin<1>);
  gg.add_moves(split_1_bin<2>);
  gg.add_moves(split_1_bin<3>);
  //g.add_moves(split_1_bin<4>);
 // repab(i,2,20) //repab(j,2,10)
 // error(i,g.findans({{i,1}}));
 // gg.add_moves(split_1_bin<2>);
  int st[]={1,1};
  int end[]={10,1};
 //gg.run(st,end,1,1);
 repab(i,1,20) error(i,gg.findans({{i,1}}));
   // gg.print();
}*/