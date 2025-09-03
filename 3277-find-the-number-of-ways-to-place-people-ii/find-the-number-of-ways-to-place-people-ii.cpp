class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b){
        if(a[0]==b[0]) return a[1]>b[1];
        return a[0]<b[0]; 
    }
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),cmp);
        int n=points.size(),ans=0;
        for(int i=0;i<n;i++){
            int tp=points[i][1];
            int mx=INT_MIN;
            for(int j=i+1;j<n;j++){
                int y=points[j][1];
                if(mx<y and y<=tp){
                    ans++;
                    mx=y;
                    if(mx==tp) break;
                }
            }
        }
        return ans;
    }
};