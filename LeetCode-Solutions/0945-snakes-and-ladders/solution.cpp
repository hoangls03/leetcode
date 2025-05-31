class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> d(n*n + 1,-1);
        queue<int> q;
        d[1] = 0;
        q.push(1);
        while ( q.size() ) {
            int u = q.front();
            q.pop();
            for ( int i = 1 ; i <= 6 && u + i <= n*n ; ++i ) {
                int val = u + i;
                int row = n - 1 - (val - 1)/n;
                int col = (val - 1)%n;
                if ( (val-1)/n & 1 ) col = n - 1 - col;
                if ( board[row][col] != -1 ) {
                    val = board[row][col];
                }
                
                if ( d[val] == -1 ) {
                    q.push(val);
                    d[val] = d[u] + 1;
                }
                if ( val == n*n ) {
                    return d[val];
                }
            }
        }
        return -1;
    }
};
