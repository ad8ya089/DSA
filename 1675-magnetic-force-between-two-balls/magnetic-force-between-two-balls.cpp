class Solution {
public:
    int countBalls(vector<int>&position,int diff){
        int n=position.size();
        int cnt=1;
        int prev=position[0];
        for(int i=1;i<n;i++){
            if(position[i]-prev>=diff){
                cnt++;
                prev=position[i]; 
            }
        }
        return cnt;
    }
    int maxDistance(vector<int>& position, int m) {
        int mx=*max_element(position.begin(),position.end());
        int mn=*min_element(position.begin(),position.end());
        sort(position.begin(),position.end());
        int l=1,r=mx-mn;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(countBalls(position,mid)>=m){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return r;
    }
};