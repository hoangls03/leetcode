const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};
class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int n = rows*cols;
        int count = 0;
        int dir = 0;
        int length = 1;
        int local_length = 0;
        vector<vector<int>> ans;
        vector<int> temp = {rStart,cStart};
        ans.push_back(temp);
        int turn = 0;
        while ( ans.size() < n ) {
            rStart += dx[dir];
            cStart += dy[dir];
            temp = {rStart,cStart};
            if ( 0 <= rStart && rStart < rows && 0 <= cStart && cStart < cols ) ans.push_back(temp);
            local_length++;
            count++;
            if ( local_length == length ) {
                if ( turn & 1 ) {
                    length++;
                }
                local_length = 0;
                dir = (dir + 1)%4;
                turn++;
            }
            
        }
        return ans;
    }
};
