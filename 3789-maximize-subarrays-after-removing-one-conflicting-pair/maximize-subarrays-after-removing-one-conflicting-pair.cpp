class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        vector<vector<int>>conflicts(n+2); //yeh un numbers ko store krega ek particular number ke liye jo pehle aarhe aur vaha tk issue hai subarray banana
        for(auto &p:conflictingPairs){
            int a=p[0];
            int b=p[1];
            conflicts[max(a,b)].push_back(min(a,b));
        }
        int mxLeft=0,sec_mxLeft=0;
        vector<long long> gains(n+2);
        long long validSub=0;
        for(int right=1;right<=n;right++){
            for(int left:conflicts[right]){
                if(left>mxLeft){
                    sec_mxLeft=mxLeft;
                    mxLeft=left;
                }
                else if(left>sec_mxLeft){
                    sec_mxLeft=left;
                }
            }
            validSub+=right-mxLeft;
            gains[mxLeft]+=mxLeft-sec_mxLeft;
        }
        //yeh max gain is to store the consequences of removing a conflict pair, kuch subarrays add hojaenge toh hum best choice lenge na
        long long mxGain=*max_element(gains.begin(),gains.end());
        return validSub+mxGain;
    }
};