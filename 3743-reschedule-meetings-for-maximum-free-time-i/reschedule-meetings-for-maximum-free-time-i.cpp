class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n=startTime.size();
        vector<int>free;
        free.push_back(startTime[0]-0);
        for(int i=1;i<n;i++){
            free.push_back(startTime[i]-endTime[i-1]);
        }
        free.push_back(eventTime-endTime[n-1]);
        int sum=0;
        for(int i=0;i<=k;i++){
            sum+=free[i];
        }
        int mxT=sum;
        int nxt=k+1;
        for(int i=nxt;i<free.size();i++){
            sum+=free[i]-free[i-nxt];
            mxT=max(sum,mxT);
        }
        return mxT;
    }
};