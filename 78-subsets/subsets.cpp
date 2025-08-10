class Solution {
public:
    //Recursion (take,notTake)
    int n;
    void recur(int ind,vector<vector<int>>&list,vector<int>tempList,vector<int>& nums){
        if(ind==n){
            list.push_back(tempList);
            return;
        }
        //take
        tempList.push_back(nums[ind]);
        recur(ind+1,list,tempList,nums);

        //notTake
        tempList.pop_back();
        recur(ind+1,list,tempList,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        n=nums.size();
        vector<vector<int>>list;
        vector<int>tempList;
        recur(0,list,tempList,nums);
        return list;
    }
};