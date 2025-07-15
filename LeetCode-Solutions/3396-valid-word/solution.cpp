class Solution {
public:
    bool isValid(string word) {
        if ( word.size() < 3 ) return false;
        vector<int> mark('z' + 1,0);
        mark['a'] = 1;
        mark['e'] = 1;
        mark['i'] = 1;
        mark['o'] = 1;
        mark['u'] = 1;
        mark['A'] = 1;
        mark['E'] = 1;
        mark['I'] = 1;
        mark['O'] = 1;
        mark['U'] = 1;
        int countVow = 0, countConso = 0;
        for ( auto i : word ) {
            if ( !( ('0' <= i && i <= '9') || ('a' <= i && i <= 'z') || ('A' <= i && i <= 'Z')) ) {
                return false;
            }
            countVow += mark[i];
            if ( !('0' <= i && i <= '9' ) ) countConso += ( mark[i] == 0 );
        }
        if ( countVow == 0 || countConso == 0 ) {
            return false;
        }
        return true;
    }
};
