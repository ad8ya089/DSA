class Solution {
public:
    //O(1) soln
    int numWaterBottles(int numB, int numE) {
        int extra=(numB-1)/(numE-1);
        return numB+extra;
    }
};