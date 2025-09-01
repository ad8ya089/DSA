class Solution{
public:
    double maxAverageRatio(vector<vector<int>>&classes,int extraStudents){
        priority_queue<pair<double,int>>heap;
        for(int i=0;i<classes.size();i++){
            double cur=(double)classes[i][0]/classes[i][1];
            double nxt=(double)(classes[i][0]+1)/(classes[i][1]+1);
            heap.push({nxt-cur,i});
        }
        for(int k=extraStudents;k>0;k--){
            auto[gain,idx]=heap.top();
            heap.pop();
            classes[idx][0]++;
            classes[idx][1]++;
            double cur=(double)classes[idx][0]/classes[idx][1];
            double nxt=(double)(classes[idx][0]+1)/(classes[idx][1]+1);
            heap.push({nxt-cur,idx});
        }
        double sum=0;
        for(auto&c:classes){
            sum+=(double)c[0]/c[1];
        }
        return sum/classes.size();
    }
};