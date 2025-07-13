class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int n1=players.size(),n2=trainers.size();
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int l=0,r=0,ct=0;
        while(l<n1 and r<n2){
            if(players[l]<=trainers[r]){
                ct++;l++;
            }
            r++;
        }
        return ct;
    }
};