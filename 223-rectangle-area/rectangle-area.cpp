class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int tot=(ax2-ax1)*(ay2-ay1)+(bx2-bx1)*(by2-by1);
        int x=0,y=0;
        bool f=0;
        int mn1=max(ax1,bx1);
        int mx1=min(ax2,bx2);
        int mn2=max(ay1,by1);
        int mx2=min(ay2,by2);
        int overlap=max(0,mx1-mn1)*max(0,mx2-mn2);
        return tot-overlap;
    }
};