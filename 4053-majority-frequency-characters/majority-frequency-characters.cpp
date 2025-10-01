class Solution {
public:
    string majorityFrequencyGroup(string s) {
        unordered_map<char,int> mp;
        for(char c:s){
            mp[c]++;
        }
        map<int,string>mp1;
        for(auto it:mp){
            mp1[it.second]+=it.first;
        }
        int sz=0;
        for(auto it:mp1){
            string str=it.second;
            sz=max(sz,(int)str.size());
        }
        string ans="";
        for(auto it:mp1){
            string str=it.second;
            if(sz==(int)str.size()){
                ans=str;
            }
        }
        return ans;
    }
};