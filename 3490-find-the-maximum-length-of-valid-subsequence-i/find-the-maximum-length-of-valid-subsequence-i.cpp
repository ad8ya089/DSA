class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n=nums.size();
        int odd=0,even=0;
        for(int x:nums){
            if(x%2==0) even++;
            else odd++;
        }
        //sab odd le
        int mx=odd;
        //sab even le
        mx=max(mx,even);
        bool par=true; //even hoga toh true hoga
        if(nums[0]%2!=0) par=false;
        int ct=1;
        for(int i=1;i<n;i++){
            if(nums[i]%2==0){
                if(par==true) continue;
                else{
                    par=true;
                    ct++;
                }
            }
            else{
                if(par==false) continue;
                else{
                    par=false;
                    ct++;
                }
            }
        }
        return max(mx,ct);
    }
};