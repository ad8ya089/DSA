class Solution {
public:
    long long minCost(vector<int>& b1, vector<int>& b2) {
        set<int>st;
        unordered_map<int,int>mp1,mp2;
        for(int i=0;i<b1.size();i++){
            mp1[b1[i]]++;mp2[b2[i]]++;
            st.insert(b1[i]);st.insert(b2[i]);
        }   
        int mn=*st.begin();
        set<pair<int,int>>st1,st2;
        for(auto it:st){
            if((mp1[it]+mp2[it])%2!=0) return -1;
            if(mp1[it]!=mp2[it]){
                int diff=abs(mp1[it]-mp2[it]);
                (mp1[it]>mp2[it]) ? st1.insert({it,diff/2}) : st2.insert({it,diff/2});
            }
        }
        long long ans=0;
        while(!st1.empty() and !st2.empty()){
            auto it1=*st1.begin(),it2=*st2.rbegin();
            st1.erase(st1.find(it1));
            st2.erase(st2.find(it2)); 
            if(it1.second>it2.second){
                ans+=1LL*it2.second*min({it1.first,it2.first,2*mn});
                st1.insert({it1.first,it1.second-it2.second});
            }       
            else if(it1.second<it2.second){
                ans+=1LL*it1.second*min({it1.first,it2.first,2*mn});
                st2.insert({it2.first,it2.second-it1.second});
            }
            else{
                ans+=1LL*it1.second*min({it1.first,it2.first,2*mn});
            }
        }
        return ans;
    }
};