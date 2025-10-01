class Solution {
public:
    //kya bdhiya cheez sikhi hai bey (haa lwde jo mera profile stalk kr rha tu bhi seekhle kuch)
    long long encode(int r,int c){
        return ((long long)r<<32) | (unsigned int)c;
    }
    pair<int,int> change(char ch,pair<int,int>curr,int sign){
        int r=curr.first,c=curr.second;
        if(ch=='U') curr={r,c-1*sign};
        if(ch=='D') curr={r,c+1*sign};
        if(ch=='L') curr={r+1*sign,c};
        if(ch=='R') curr={r-1*sign,c};
        return curr;
    }
    int distinctPoints(string s, int k) {
        int n=s.size();
        if(n==k) return 1; //(0,0) point hi ans hoga
        pair<int,int>curr={0,0};
        for(int i=0;i<n;i++){
            curr=change(s[i],curr,1);
        }
        unordered_set<long long>st;
        //ab hatana chalu
        for(int i=0;i<k;i++){
            curr=change(s[i],curr,-1);
        }
        st.insert(encode(curr.first,curr.second));
        for(int i=0;i<n-k;i++){
            curr=change(s[i],curr,1);
            curr=change(s[i+k],curr,-1);
            st.insert(encode(curr.first,curr.second));
        }
        return (int)st.size();
    }
};