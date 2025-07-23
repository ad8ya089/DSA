class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int moves=0;
        while(target!=1 and maxDoubles){
            if(target%2!=0){
                target--;
                moves++;
            }
            else{
                target/=2;
                moves++;
                maxDoubles--;
            }
        }
        return moves+target-1;
    }
};