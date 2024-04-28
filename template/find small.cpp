
/// Name: find number between s and t
/// Guarantee: bool findstring(string &s,string &t,set<char> &pos,string &ans,int i=0,bool low=true,bool high=true){

bool findstring(string &s,string &t,set<char> &pos,string &ans,int i=0,bool low=true,bool high=true){
    if(i==sz(s)) return true;
    
    if(low && pos.find(s[i])!=pos.end()) {
        string tmpans=ans+s[i];
        if(findstring(s,t,pos,tmpans,i+1,low,s[i]==t[i])) {
            ans=tmpans;
            return true;
        }
    }
    iter(x,pos) {
        if((!low || s[i]<x) && (!high || x<t[i]))  {
            ans+=x;
            rep(j,sz(s)-i-1) ans+=*pos.begin();
            return true;
        }
    }
    if(high && s[i]!=t[i] && pos.find(t[i])!=pos.end()) {
        string tmpans=ans+t[i];
        if(findstring(s,t,pos,tmpans,i+1,s[i]==t[i],high)) {
            ans=tmpans;
            return true;
        }
    }
    return false;
}
