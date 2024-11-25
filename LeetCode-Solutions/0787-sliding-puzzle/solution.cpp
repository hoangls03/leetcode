const int dx[] = {-1,0,0,1};
const int dy[] = {0,-1,1,0};
class Solution {
public:
    bool check( vector<vector<int>>& a, vector<vector<int>>& b ) {
        for ( int i = 0 ; i < 2 ; ++i ) {
            for ( int j = 0 ; j < 3 ; ++j ) {
                if ( a[i][j] != b[i][j] ) return false;
            }
        }
        return true;
    }
    bool valid( int i, int j, int m , int n ) {
        if ( 0 <= i && i < m && 0 <= j && j < n ) return true;
        return false;
    }
    int slidingPuzzle(vector<vector<int>>& board) {
        queue<vector<vector<int>>> q;
        map<vector<vector<int>>,int> mp;
        q.push(board);
        vector<vector<int>> res(2,vector<int>(3,0));
        for ( int i = 0 ; i < 2 ; ++i ) {
            for ( int j = 0 ; j < 3 ; ++j ) {
                res[i][j] = i*3 + j + 1;
            }
        }
        res[1][2] = 0;
        mp[board] = 1;
        while ( q.size() ) {
            auto tmp = q.front();
            
            q.pop();
            for ( int i = 0 ; i < 2 ; ++i ) {
                for ( int j = 0 ; j < 3 ; ++j ) {
                    if ( tmp[i][j] == 0 ) {
                        for ( int k = 0 ; k < 4 ; ++k ) {
                            if ( valid(i+dx[k],j+dy[k],2,3) ) {
                                auto v = tmp;
                                swap(v[i][j],v[i+dx[k]][j+dy[k]]);
                                if ( mp[v] == 0 || mp[tmp] + 1 < mp[v] ) {
                                    mp[v] = mp[tmp] + 1;
                                    q.push(v);
                                }
                            }
                        }
                    }
                }
            }
        }
        return mp[res] - 1;
    }
};
