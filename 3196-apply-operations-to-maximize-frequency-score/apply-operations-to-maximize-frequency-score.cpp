class Solution {
public:
    int n;
    bool possible(vector<int>& nums,vector<long long>&prefix,int len, long long k){
        //len is length of window we will check possibility from
        for(int i=0;i+len<=n;i++){
            int j=i+len-1;
            int m=i+len/2; //this is median element index -> can also write (i+j)/2
            long long left=prefix[m]-prefix[i]; //i se m-1 tk ka sum
            long long right=prefix[j+1]-prefix[m+1]; //1 based index hai isliye bad wale index mei 1 add krke kro, ismei hum m ke baad jo right elements hai uska nikal rhe: m+1->j
            long long cost=(1LL*(m-i)*nums[m]-left)+(right-1LL*(j-m)*nums[m]);
            if(cost<=k) return 1; 
        }
        return 0;
    }
    int maxFrequencyScore(vector<int>& nums, long long k) {
        sort(nums.begin(),nums.end());
        n=nums.size();
        int ans=0;
        vector<long long>prefix(n+1);
        //1 based prefix array bana rhe
        for(int i=0;i<n;i++){
            prefix[i+1]=prefix[i]+nums[i];
        }
        int mn=1,mx=n; //kitne size ka window le skte h min and max(jsmei sb same ho)
        while(mn<=mx){
            int mid=(mn+mx)/2;  
            if(possible(nums,prefix,mid,k)){
                ans=mid;
                mn=mid+1;
            }
            else{
                mx=mid-1;
            }
        }
        return ans;
    }
};