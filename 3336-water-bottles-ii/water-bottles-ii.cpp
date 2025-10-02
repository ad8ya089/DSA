class Solution {
public:
    int maxBottlesDrunk(int numB, int numE) {
        int totD=0;
        while(numB>=numE){
            totD+=numE; //pee le
            numB-=numE; //hata de
            numE++; //cost badha
            numB++; //1 new bottle
        }
        return totD+numB;
    }
};