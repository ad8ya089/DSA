class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n=startTime.size();
        vector<int> free;
        free.push_back(startTime[0]-0);
        for(int i=1;i<n;i++){
            free.push_back(startTime[i]-endTime[i-1]);
        }
        free.push_back(eventTime-endTime[n-1]);
        int win=k+1;
        int sum=0,mx=0;
        for(int i=0;i<k+1;i++){
            sum+=free[i];
        }
        mx=max(mx,sum);
        for(int i=k+1;i<n+1;i++){
            sum+=free[i];
            sum-=free[i-k-1];
            mx=max(mx,sum);
        }
        return mx;
    }
};