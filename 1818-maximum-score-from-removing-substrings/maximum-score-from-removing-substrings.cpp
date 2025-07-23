class Solution {
public:
    //Two pointer approach(wihtout stack)
    int removePattern(string &s,char first,char second,int score){
        int w=0; //write and read pointers
        int gain=0;
        for(int r=0;r<s.size();r++){
            s[w++]=s[r];
            if(w>=2 and s[w-2]==first and s[w-1]==second){
                gain+=score;
                w-=2;
            }
        }
        string str="";
        for(int i=0;i<w;i++){
            str+=s[i];
        }
        s=str;
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