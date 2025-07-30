class Solution {
public:
    int cntW(string &s){
        int ct=0;
        for(char c:s){
            if(c==' ') ct++;
        }
        return ct+1;
    }
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        int n=messages.size();
        unordered_map<string,int>mp;
        for(int i=0;i<n;i++){
            mp[senders[i]]+=cntW(messages[i]);
        }
        int mx=0;
        string ans="";
        for(auto it:mp){
            string s=it.first;
            int cnt=it.second;
            if(cnt>mx){
                mx=cnt;
                ans=s;
            }
            if(cnt==mx){
                ans=max(ans,s);
            }
        }
        return ans;
    }
};