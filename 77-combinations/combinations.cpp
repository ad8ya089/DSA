class Solution {
public:
    void backtrack(int start,vector<vector<int>>&list,vector<int>&tempList,int k,int n){
        if(tempList.size()==k){
            list.push_back(tempList);
            return;
        }
        for(int i=start;i<=n;i++){
            tempList.push_back(i);
            backtrack(i+1,list,tempList,k,n);
            tempList.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>list;
        vector<int>tempList;
        backtrack(1,list,tempList,k,n);
        return list;
    }
};