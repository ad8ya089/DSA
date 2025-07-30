class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        int mx=-1,ans=-1;
        for(auto it:mp){
            if(it.first%2==0){
                if(it.second>mx){
                    mx=it.second;
                    ans=it.first;
                }
                if(it.second==mx){
                    ans=min(ans,it.first);
                }
            }
        }
        return ans;
    }
};