class Solution {
public:
    // Aryan's backtracking template
    void backtrack(int ind,vector<string>&list ,string&tempList,vector<string>&mp,string digits){
        if(ind==digits.size()){
            list.push_back(tempList);
            return;
        }
        int num=digits[ind]-'0';
        string curr=mp[num];
        for(int i=0;i<curr.size();i++){
            tempList.push_back(curr[i]);
            backtrack(ind+1,list,tempList,mp,digits);
            tempList.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return {};
        vector<string>list;
        string tempList="";
        vector<string>mp(10,"");
        mp[2]="abc";mp[3]="def";mp[4]="ghi";mp[5]="jkl",mp[6]="mno",mp[7]="pqrs";mp[8]="tuv";mp[9]="wxyz";
        backtrack(0,list,tempList,mp,digits);
        return list;
    }   
};