class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //kth largest pucha h isliye min heap, kth smallest puchta toh max heap
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int num:nums){
            pq.push(num);
            if(pq.size()>k){
                pq.pop();
            }
        }
        return pq.top();
    }
};