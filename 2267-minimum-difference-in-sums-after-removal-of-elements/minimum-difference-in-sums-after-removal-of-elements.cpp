class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int tot=nums.size(),n=tot/3;
        long long sum=0;
        vector<long long> part1(n + 1);
        //max heap -->max element ko hata coz minimum sum hona chahiye part 1 ka
        priority_queue<int>pq1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            pq1.push(nums[i]);
        }
        part1[0]=sum;
        for(int i=n;i<n*2;++i){
            sum+=nums[i];
            pq1.push(nums[i]);
            sum-=pq1.top();
            pq1.pop();
            part1[i-(n-1)]=sum;
        }
        //min heap -->min element ko hata coz maximum sum hona chahiye part 2 ka
        priority_queue<int,vector<int>,greater<int>>pq2;
        long long part2=0;
        for(int i=n*3-1;i>=n*2;i--){
            part2+=nums[i];
            pq2.push(nums[i]);
        }
        long long ans=part1[n]-part2;
        for(int i=n*2-1;i>=n;i--){
            part2+=nums[i];
            pq2.push(nums[i]);
            part2-=pq2.top();pq2.pop();
            ans=min(ans,part1[i-n]-part2);
        }
        return ans;
    }
};