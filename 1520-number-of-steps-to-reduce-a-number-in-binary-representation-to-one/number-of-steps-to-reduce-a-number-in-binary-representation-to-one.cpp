class Solution {
public:
    int numSteps(string s) {
        //hum string ko int mei convert ni kr skte atleast C++ mei coz 2^500 kaise likhega tu bsdk , thoda toh dimag laga, string mei hi try kr change krne ka
        int moves=0;
        while(s!="1"){
            //ab string even ko represent krega toh last mei 0 hoga, kyuki 2^0=1 ko add krega uske decimal representation mei toh odd hojaega na number 
            if(s[s.size()-1]=='0'){
                s.pop_back(); //divide by 2 krenge toh last wala zero hat jaega
            }
            //odd hua toh last mei 1 rhega hi ,toh tujhe kya krna hoga ki piche se first 0 tk sbko 0 bnate ja aur uss 0 ko 1 banade, agar zero hai hi ni toh pure ko zero banake 1 add krde
            else{
                int n=s.size();
                bool f=0;
                for(int i=n-1;i>=0;i--){
                    if(s[i]=='0'){
                        f=1;
                        s[i]='1';
                        break;
                    }
                    s[i]='0';
                }
                if(!f) s='1'+s;
            }
            moves++;
        }
        return moves;
    }
};