class Solution {
public:
    int maxSum(vector<int>& nums) {
        int sum=0,n=nums.size();
        int pos=0,zero=0,neg=0,mx=-101;
        unordered_set<int>st;
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                st.insert(nums[i]);
                pos++;
            }
            else if(nums[i]==0) zero++;
            else neg++;
            mx=max(mx,nums[i]);
        }
        for(auto it:st){sum+=it;}
        if(pos!=0) return sum;
        else{
            if(zero!=0) return 0;
            else return mx;
        }
    }
};