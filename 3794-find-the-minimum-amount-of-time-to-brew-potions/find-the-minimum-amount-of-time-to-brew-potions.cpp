class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n=skill.size(),m=mana.size();
        vector<long long>finish(n,0);
        for(int j=0;j<m;j++){
            finish[0]+=1LL*skill[0]*mana[j];
            for(int i=1;i<n;i++){
                finish[i]=max(finish[i],finish[i-1])+1LL*skill[i]*mana[j]; //potion aur wizard dono khali hai na koi bhi use mei toh ni hai ya use kr toh ni rha
            }
            for(int i=n-2;i>=0;i--){
                finish[i]=finish[i+1]-1LL*skill[i+1]*mana[j];
            }
        }
        return finish[n-1];
    }
};