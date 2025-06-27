class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int n=barcodes.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[barcodes[i]]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto it:mp){
            pq.push({it.second,it.first});
        }
        vector<int>result;
        while(!pq.empty()){
            auto first=pq.top();
            pq.pop();
            if(result.empty() or result.back()!=first.second){
                result.push_back(first.second);
                first.first--;

                if(first.first>0){
                    pq.push(first);
                }
            }
            else{
                auto second=pq.top();
                pq.pop();
                result.push_back(second.second);
                second.first--;

                if(second.first>0){
                    pq.push(second);
                }
                pq.push(first);
            }
        }
        return result;
    }
};