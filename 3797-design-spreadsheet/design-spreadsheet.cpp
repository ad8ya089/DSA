class Spreadsheet {
public:
    vector<vector<int>>res;
int getCellVal(const string &cell){
    char c=cell[0];
    int x=stoi(cell.substr(1))-1;
    int y=c-65;
    return res[x][y];
}
    Spreadsheet(int rows) {
        res.resize(rows,vector<int>(26,0));
    }
    
    void setCell(string cell, int value) {
        char c=cell[0];
        int x=stoi(cell.substr(1))-1;
        int y=c-65;
        res[x][y]=value;
    }
    
    void resetCell(string cell) {
        char c=cell[0];
        int x=stoi(cell.substr(1))-1;
        int y=c-65;
        res[x][y]=0;
    }
    
    int getValue(string formula) {
        formula=formula.substr(1); // '=' ki zroorat ni
        size_t plus=formula.find('+');
        string p1=formula.substr(0,plus);
        string p2=formula.substr(plus+1);

        int v1=isdigit(p1[0])?stoi(p1):getCellVal(p1);
        int v2=isdigit(p2[0])?stoi(p2):getCellVal(p2);
        return v1+v2;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */