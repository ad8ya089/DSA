class Solution {
public:
    string reorganizeString(string s) {
        int n=s.size();
        vector<int>v(26);
        for(int i=0;i<n;i++){
            v[s[i]-'a']++;
        }
        priority_queue<pair<int,char>>pq;
        for(int i=0;i<26;i++){
            if(v[i]) pq.push({v[i],(char)(i+'a')});
        }
        string str="";
        pair<int,char>prev={0,'*'};
        while(!pq.empty()){
            auto it=pq.top();pq.pop();
            int ct=it.first;
            char ch=it.second;
            str+=ch;
            if(prev.first>0){
                pq.push(prev);
            }
            prev={ct-1,ch};
        }
        return (str.size()==s.size())?str:"";
    }
};