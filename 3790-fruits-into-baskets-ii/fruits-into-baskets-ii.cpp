class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();
        int ct=0;
        set<int>st;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(!st.count(j) and baskets[j]>=fruits[i]){
                    st.insert(j);
                    ct++;
                    break;
                }
            }
        }
        return n-ct;
    }
};