class Solution {
public:
    bool isPowerofTwo(string s){
        int num=stoi(s);
        if((num&(num-1))==0) return 1;
        return 0;
    }
    int n1;
    bool f(int ind,string str){
        if(ind==n1){
            if(str[0]=='0') return false;
            if(isPowerofTwo(str)) return true;
            return false;
        }
        for(int i=ind;i<n1;i++){
            swap(str[i],str[ind]);
            if(f(ind+1,str)) return true;
            swap(str[i],str[ind]);
        }
        return false;
    }
    bool reorderedPowerOf2(int n) {
        string str=to_string(n);
        n1=str.size();
        if(f(0,str)) return true;
        return false;
    }
};