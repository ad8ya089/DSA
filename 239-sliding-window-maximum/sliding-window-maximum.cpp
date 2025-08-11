class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        deque<int>dq;
        dq.push_back(nums[0]);
        for(int i=1;i<k;i++){
            while(!dq.empty() and nums[i]>dq.back()){
                dq.pop_back();
            }
            dq.push_back(nums[i]);
        }
        vector<int>ans;
        ans.push_back(dq.front());
        for(int i=k;i<n;i++){
            if(nums[i-k]==dq.front()){
                dq.pop_front();
            }
            while(!dq.empty() and nums[i]>dq.back()){
                dq.pop_back();
            }
            dq.push_back(nums[i]);
            ans.push_back(dq.front());
        }
        return ans;
    }
};