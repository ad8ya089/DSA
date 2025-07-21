class Solution {
public:
    //Easier Method
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int>ans;
        for(auto q:queries){
            int x=q[0],y=q[1];
            int cx=0,cy=0;
            //niche se upar jaa rhe till LCA
            while(x!=y){
                if(x>y){
                    x/=2;
                    cx++;
                }
                else{
                    y=y/2;
                    cy++;
                }
            }
            ans.push_back(cx+cy+1);
        }
        return ans;
    }
};