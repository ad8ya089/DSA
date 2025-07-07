class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n=events.size();
        sort(events.begin(),events.end());
        //min heap
        priority_queue<int,vector<int>,greater<int>>pq;
        int day=0,i=0,ct=0;
        while(i<n or !pq.empty()){
            if(pq.empty()){
                day=events[i][0];
            }
            while(i<n and events[i][0]==day){
                pq.push(events[i][1]);
                i++;
            }
            if(!pq.empty()){
                pq.pop();
                ct++;day++;
            }
            while(!pq.empty() and pq.top()<day){
                pq.pop();
            }
        }
        return ct;
    }
};