class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int n=weight.size();
        int ct=0,mx=weight[0];
        for(int i=1;i<n;i++){
            if(weight[i]<mx){
                ct++;
                if(i==n-1) break;
                mx=weight[i+1];
            }
            else{
                mx=max(mx,weight[i]);
            }
        }
        return ct;
    }
};