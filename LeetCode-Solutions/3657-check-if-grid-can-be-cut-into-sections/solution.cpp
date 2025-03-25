class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> row,col;
        for ( auto rec : rectangles ) {
            row.push_back({rec[0],rec[2]});
            col.push_back({rec[1],rec[3]});
        }
        sort(row.begin(),row.end());
        sort(col.begin(),col.end());
        
        int r = row[0][1];
        int ans = 0;
        for ( int i = 1 ; i < row.size() ; ++i ) {
            if ( r <= row[i][0] ) {
                ans++;
            }
            r = max(r,row[i][1]);
        }
        if ( ans >= 2 ) return true;
        ans = 0;
        r = col[0][1];
        for ( int i = 1 ; i < col.size() ; ++i ) {
            if ( r <= col[i][0] ) {
                ans++;
            }
            r = max(r,col[i][1]);
        }
        return ( ans >= 2);
    }
};
