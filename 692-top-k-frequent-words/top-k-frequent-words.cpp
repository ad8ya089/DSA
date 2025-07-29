class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n=words.size();
        priority_queue<pair<int,string>> pq;
        unordered_map<string,int>mp;
        for(int i=0;i<n;i++){
            mp[words[i]]++;
        }
        //max heap ko min heap bna diya taaki lexicographical order m store ho jaaye
        for(auto it:mp){
            pq.push({-it.second,it.first});
            if(pq.size()>k) pq.pop();
        }
        vector<string>ans;
        for(int i=0;i<k;i++){
            string str=pq.top().second;pq.pop();
            ans.push_back(str);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};