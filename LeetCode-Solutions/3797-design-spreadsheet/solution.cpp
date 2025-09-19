class Spreadsheet {
public:
    vector<vector<int>> sheet;
    Spreadsheet(int rows) : sheet('Z' + 1){
        for ( int j = 'A' ; j <= 'Z' ; ++j ) {
            for ( int i = 0 ; i <= rows ; ++i ) {
                sheet[j].push_back(0);    
            }
        }   
    }
    
    void setCell(string cell, int value) {
        int num = 0;
        for ( auto i : cell ) {
            if ( '0' <= i && i <= '9' ) num = num*10 + (i - '0');
        }
        sheet[cell[0]][num] = value;
    }
    
    void resetCell(string cell) {
        int num = 0;
        for ( auto i : cell ) {
            if ( '0' <= i && i <= '9' ) num = num*10 + (i - '0');
        }
        sheet[cell[0]][num] = 0;
    }
    
    int getValue(string formula) {
        char col = 0;
        int num = 0;
        int val = 0;
        for ( auto i : formula ) {
            if ( i == '=' ) {
                continue;
            }
            if ( i == '+' ) {
                if ( col != 0 ) {
                    val += sheet[col][num];
                } else {
                    val += num;
                }
                col = 0;
                num = 0;
                continue ;
            }
            if ( 'A' <= i && i <= 'Z' ) {
                col = i;
            } else {
                num = num*10 + (i - '0');
            }
        }
        if ( col != 0 ) {
            val += sheet[col][num];
        } else {
            val += num;
        }
        return val;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
