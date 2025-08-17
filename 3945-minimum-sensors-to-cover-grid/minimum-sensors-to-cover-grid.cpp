class Solution {
public:
    int minSensors(int n, int m, int k) {
        int hor=(n+2*k)/(2*k+1);
        int ver=(m+2*k)/(2*k+1);
        return hor*ver;
    }
};