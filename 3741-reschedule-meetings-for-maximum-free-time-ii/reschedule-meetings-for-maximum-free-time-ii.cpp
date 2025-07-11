class Solution {
public:
    int maxFreeTime(int t, vector<int>& s, vector<int>& e) {
        vector<int> f;
        f.push_back(s[0]);
        for(int i = 1; i < s.size(); i++) {
            f.push_back(s[i] - e[i-1]);
        }
        f.push_back(t - e[e.size()-1]);
        int n = f.size();
        vector<int> r(n, 0), l(n, 0);
        for(int i = n-2; i >= 0; i--) {
            r[i] = max(r[i+1], f[i+1]);
        }
        for(int i = 1; i < n; i++) {
            l[i] = max(l[i-1], f[i-1]);
        }
        int res = 0;
        for(int i = 1; i < n; i++) {
            int d = e[i-1] - s[i-1];
            if(d <= max(l[i-1], r[i])) {
                res = max(res, f[i-1] + d + f[i]);
            }
            res = max(res, f[i-1] + f[i]);
        }
        return res;
    }
};