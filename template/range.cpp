/// Name: range operations
/// Guarantee: void insert(array(2) range){
set<array(2)> vals;
map<array(2),int> mp_ids;
void insert(array(2) range){
    int id=sz(vals)/2;
    vals.insert({range[0],0});
    vals.insert({range[1],1});
    mp_ids[{range[0],range[1]}]=id;
}
array(3) find_range(int val){
    auto x=vals.lower_bound({val,0});
    if(x==vals.end()) return {-1,-1,-1};
    auto res=*x;
    if(res[1]==0) {
        if(res[0]>val) return {-1,-1,-1};
        array(3) ans={res[0],res[1],0};
        x++;
        res=*x;
        ans[1]=res[0];
        ans[2]=mp_ids[{ans[0],ans[1]}];
        return ans;
    }
    
        array(3) ans={res[1],res[0],0};
        x--;
        res=*x;
        ans[0]=res[0];
        ans[2]=mp_ids[{ans[0],ans[1]}];
        return ans;
    
}
void remove(array(2) range){
    vals.erase({range[0],0});
    vals.erase({range[1],1});
    mp_ids.erase({range[0],range[1]});
}
void insert_merge(array(2) range){
    auto x=vals.lower_bound({range[0],0});
    auto res=*x;
    while(x!=vals.end() && res[0]<=range[1]){
        auto torem=find_range(res[0]);
        remove({torem[0],torem[1]});
        x=vals.lower_bound({range[0],0});    
        res=*x;
    }
    insert(range);
}