class Solution {
public:
    int maxJump(vector<int>& stones) {
        int n=stones.size();
        int mx=stones[1]-stones[0];
        for(int i=3;i<n;i+=2){
            mx=max(mx,stones[i]-stones[i-2]);
        }
        for(int i=2;i<n;i+=2){
            mx=max(mx,stones[i]-stones[i-2]);
        }
        return mx;
    }
};