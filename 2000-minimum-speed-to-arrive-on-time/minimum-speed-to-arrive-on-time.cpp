class Solution {
public:
    double time(vector<int>&dist,int speed){
        int n=dist.size();
        double sum=0.0;
        for(int i=0;i<n-1;i++){ //kyuki pehle numers ka ceil lenge integer pe hi depart hoga na isliye
            sum+=ceil((double)dist[i]/(double)speed);
        }
        sum+=(double)dist[n-1]/(double)speed;
        return sum;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n=dist.size();
        int l=1,r=1e7; //max element ni liye kyuki yaha float values bhi allowed hai integer hote toh max element ko r rkhte
        int ans=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(time(dist,mid)<=hour){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};