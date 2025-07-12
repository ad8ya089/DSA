class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele=0,ct=0;
        for(int i=0;i<nums.size();i++){
            if(ct==0){
                ele=nums[i];
                ct++;
                continue;
            }
            if(nums[i]==ele){
                ct++;
            }
            else{
                ct--;
            }
        }
        return ele;
    }
};