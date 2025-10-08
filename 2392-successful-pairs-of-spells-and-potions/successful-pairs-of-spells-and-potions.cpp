class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n=spells.size(),m=potions.size();
        sort(potions.begin(),potions.end());
        vector<int>ans;
        for(int i=0;i<n;i++){
            long long req=ceil((double)success/(double)spells[i]);
            if(success%spells[i]==0) req=success/spells[i];
            int ind=lower_bound(potions.begin(),potions.end(),req)-potions.begin();
            ans.push_back(m-ind);
        }
        return ans;
    }
};