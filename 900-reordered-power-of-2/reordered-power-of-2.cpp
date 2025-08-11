class Solution {
public:
    unordered_set<string>st;
    void buildSet(){
        for(int p=0;p<=30;p++){ //10^9 tk 29 se hi kaam hojaata vaise
            string s=to_string(1<<p);
            sort(s.begin(),s.end());
            st.insert(s);
        }
    }
    bool reorderedPowerOf2(int n) {
        if(st.empty()){
            buildSet();
        }
        string str=to_string(n);
        sort(str.begin(),str.end());
        return st.count(str);
    }
};