class Solution {
public:
    bool possible(long long minTime,vector<int>& ranks, int cars){
        int n=ranks.size();
        long long totCars=0;
        for(int r:ranks){
            long double timePerCar=(long double)minTime/r;
            long long div=floor(sqrt(timePerCar));
            totCars+=div;
            if(totCars>=cars) return true;
        }
        return false;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        int mn=*min_element(ranks.begin(),ranks.end());
        long long l=1,r=1LL*cars*cars*mn,ans=0;
        while(l<=r){
            long long mid=(l+r)/2;
            if(possible(mid,ranks,cars)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};