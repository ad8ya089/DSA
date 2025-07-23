class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        if(maxDoubles==0 or target==1) return target-1;
        if(maxDoubles==1){
            int moves=1;
            if(target%2==0){
                target/=2;
            }
            else{
                moves++;
                target--;
                target/=2;
            }
            return target-1+moves;
        }
        int moves=0;
        while(target!=1){
            if(target%2!=0 or maxDoubles==0){
                target--;
                moves++;
            }
            else{
                target/=2;
                moves++;
                maxDoubles--;
            }
        }
        return moves;
    }
};