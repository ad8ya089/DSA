class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        int l=0,r=0;
        unordered_map<int,int>mp;
        int mx=0;
        while(r<n){
            mp[fruits[r]]++;
            while(l<=r and mp.size()>2){
                mp[fruits[l]]--;
                if(mp[fruits[l]]==0) mp.erase(fruits[l]);
                l++;
            }
            mx=max(mx,r-l+1);
            r++;
        }
        return mx;
    }
};