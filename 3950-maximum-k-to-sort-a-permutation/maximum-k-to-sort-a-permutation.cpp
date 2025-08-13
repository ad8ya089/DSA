class Solution {
public:
    //intermediate value k lele such that each misplaced element , a&k==k
    //ab humlog ko yhi pta krna h ki lets say misplaced elements are {a,b,c,d}
    //now a&k==k,b&k==k,c&k==k,d&k==k toh max k kya hoga jismei {a,b,c,d} ke saare bits set ho --> toh jb notice kroge voh k literally a&b&c&d hi hoga (dry run krke dekh)
    int sortPermutation(vector<int>& nums) {
        int n=nums.size();
        int val=~0; //saare bits 1
        for(int i=0;i<n;i++){
            if(nums[i]!=i){ //not in its place
                val=val&i;
            }
        }
        if(val==~0) return 0;
        return val;
    }   
};