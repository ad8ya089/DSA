class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        //string print krne ka try mt kr kyuki constraint will take it to 2^100 size which is not possible
        int ctOps=0;
        long long val=k;
        while(val>1){
            int jumps=ceil(log2(val));
            val-=pow(2,jumps-1);
            ctOps+=operations[jumps-1];
        }
        return char('a'+(ctOps%26));
    }
};