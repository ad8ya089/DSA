class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>mp(26);
        priority_queue<int>pq;
        for(auto t:tasks){
            mp[t-'A']++;
        }
        for(int i=0;i<26;i++){
            if(mp[i]) pq.push(mp[i]);
        }
        int interval=0;
        while(!pq.empty()){
            vector<int>left;
            int cyc=n+1;
            while(cyc and !pq.empty()){
                int mx=pq.top();pq.pop();
                if(mx>1){
                    left.push_back(mx-1);
                }
                interval++;
                cyc--;
            }
            for(int freq:left){
                pq.push(freq);
            }
            if(pq.empty()) break;
            interval+=cyc;
        }
        return interval;
    }
};