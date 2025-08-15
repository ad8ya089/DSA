class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for(int i=1;i<n;i++){
            int currOne=intervals[i][0],currTwo=intervals[i][1];
            int prevOne=ans.back()[0],prevTwo=ans.back()[1];
            if(prevTwo>=currOne){
                ans.back()[1]=max(currTwo,prevTwo);
            }
            else{
                ans.push_back({currOne,currTwo});
            }
        }
        return ans;
    }
};