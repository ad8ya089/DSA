class Solution {
public:
    long long flowerGame(int n, int m) {
        int odd1=(n/2)+(n%2),even1=(n/2);
        int odd2=(m/2)+(m%2),even2=(m/2);
        long long ans1=0;
        for(int i=0;i<odd1;i++){
            ans1+=even2;
        }
        long long ans2=0;
        for(int i=0;i<odd2;i++){
            ans2+=even1;
        }
        return ans1+ans2;
    }
};