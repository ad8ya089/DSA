class Solution {
public:
    int stoneGameVI(vector<int>& a1, vector<int>& b1) {
        vector<vector<int>>v;

        int n=a1.size();
        for(int i=0;i<n;i++){
            v.push_back({a1[i]+b1[i],a1[i],b1[i]});
        }
        sort(v.begin(),v.end(),greater<vector<int>>());
        int a=0,b=0;
        for(int i=0;i<n;i++){
            if(i%2==0){
                a+=v[i][1]; //alice's turn
            }
            else{
                b+=v[i][2]; //bob's turn
            }
        }
        if(a==b) return 0;
        if(a>b) return 1;
        return -1;
    }
};