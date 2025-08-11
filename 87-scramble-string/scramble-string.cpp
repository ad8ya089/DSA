class Solution {
public:
map<pair<string,string>,int>mp;


bool rec(int n,string a,string b)
{
    if(a.compare(b)==0)
    {
        return true;
    }
    if(a.length()<=1) return false;

    if(mp.find({a,b})!=mp.end())
    {
        return mp[{a,b}]; 
    }

    bool f=false;
    for(int i=1;i<n;i++)
    {
        if((rec(i,a.substr(0,i),b.substr(0,i)) and rec(n-i,a.substr(i,n-i),b.substr(i,n-i))) or (rec(i,a.substr(0,i),b.substr(n-i,i)) and rec(n-i,a.substr(i,n-i),b.substr(0,n-i))))
        {
            return mp[{a,b}]=true;
        }
    }
    return mp[{a,b}]=f;
}
    bool isScramble(string s1, string s2) {
        int n=s1.size();
        return rec(n,s1,s2);
        
    }
};