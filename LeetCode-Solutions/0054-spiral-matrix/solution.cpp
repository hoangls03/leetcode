const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int x = 0;
        int y = 0;
        vector<int> ans;
        int dir = 0;
        vector<vector<bool>> check(m,vector<bool>(n));
        int count = 0;
        while ( count != m*n ) {
            count++;
            ans.push_back(matrix[x][y]);
            int newX = x + dx[dir];
            int newY = y + dy[dir];
            check[x][y] = true;
            if ( 0 <= newX && newX < m && 0 <= newY && newY < n && !check[newX][newY] ) {
                x = newX;
                y = newY;
            } else {
                dir = (dir + 1)%4;
                x = x + dx[dir];
                y = y + dy[dir];
            }
        }
        return ans;
    }
};
