class Solution {
public:
    int removePattern(string &s,char first,char second,int score){
        stack<char>st;
        int gain=0;
        for(char c:s){
            if(c==second){
                if(!st.empty() and st.top()==first){
                    gain+=score;
                    st.pop();
                }
                else st.push(c);
            }
            else st.push(c);
        }
        s.clear();
        while(!st.empty()){
            s+=st.top();
            st.pop();
        }
        reverse(s.begin(),s.end());
        return gain;
    }
    int maximumGain(string s, int x, int y) {
        int n=s.size();
        int ans=0;
        if(x>y){
            ans+=removePattern(s,'a','b',x); //pehle x hatao
            ans+=removePattern(s,'b','a',y); //fir y hatao
        }
        else{
            ans+=removePattern(s,'b','a',y);
            ans+=removePattern(s,'a','b',x);
        }
        return ans;
    }
};