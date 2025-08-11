class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string str=to_string(n);
        int n1=str.size();
        sort(str.begin(),str.end());
        set<string>st;
        for(int i=0;i<31;i++){
            int num=pow(2,i);
            string s=to_string(num);
            sort(s.begin(),s.end());
            st.insert(s);
        }
        if(st.count(str)) return true;
        return false;
    }
};