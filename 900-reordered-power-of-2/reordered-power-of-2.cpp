class Solution {
public:
    //Approach 3- vector count (sort krne ka need ni)
    
    bool reorderedPowerOf2(int n) {
        string str=to_string(n);
        vector<int>cnt(10,0);
        for(int i=0;i<str.size();i++){
            cnt[str[i]-'0']++;
        }
        for(int p=0;p<=29;p++){
            string s=to_string(1<<p);
            vector<int>cntTwo(10,0);
            for(int i=0;i<s.size();i++){
                cntTwo[s[i]-'0']++;
            }
            if(cntTwo==cnt) return true;
        }
        return false;
    }
};