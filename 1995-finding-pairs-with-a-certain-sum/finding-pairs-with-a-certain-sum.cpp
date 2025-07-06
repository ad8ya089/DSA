class FindSumPairs {
public:
    vector<int>nums1,nums2;
    unordered_map<int,int>mp;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1=nums1;
        this->nums2=nums2;
        for(int j=0;j<nums2.size();j++){
            mp[nums2[j]]++;
        }
    }
    
    void add(int index, int val) {
        mp[nums2[index]]--;
        nums2[index]+=val;
        mp[nums2[index]]++;
    }
    
    int count(int tot) {
        int ct=0;
        for(int i=0;i<nums1.size();i++){
            if(mp.count(tot-nums1[i])){
                ct+=mp[tot-nums1[i]];
            }
        }
        return ct;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */