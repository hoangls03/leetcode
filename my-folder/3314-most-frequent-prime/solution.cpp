bool prime(int n) {
    if ( n < 2 ) return false;
    for ( int i = 2 ; i <= trunc(sqrt(n)) ; ++i ) {
        if  ( n % i == 0 ) return false;
    }
    return true;
}
class Solution {
public:
    int mostFrequentPrime(vector<vector<int>>& mat) {
        vector<int> vt;
        map<int,int> mp;
        int ans = -1;
        int m = mat.size();
        int n = mat[0].size();
        for ( int i = 0 ; i < m ; ++i ) {
            for ( int j = 0 ; j < n ; ++j ) {
                int row = i - 1, col = j - 1, temp = mat[i][j];
                if ( prime(mat[i][j]) ) vt.push_back(mat[i][j]);
                while ( row < m && col < n && row >= 0 && col >= 0 ) {
                    temp = temp*10 + mat[row][col];
                    if ( prime(temp) ) {
                        vt.push_back(temp);
                        
                    }
                    row--;
                    col--;
                }
                row = i - 1, col = j, temp = mat[i][j];
                while ( row < m && col < n && row >= 0 && col >= 0 ) {
                    temp = temp*10 + mat[row][col];
                    if ( prime(temp) ) {
                        vt.push_back(temp);
                        
                    }
                    row--;
                }
                row = i - 1, col = j + 1, temp = mat[i][j];
                while ( row < m && col < n && row >= 0 && col >= 0 ) {
                    temp = temp*10 + mat[row][col];
                    if ( prime(temp) ) {
                        vt.push_back(temp);
                        
                    }
                    row--;
                        col++;
                }
                row = i, col = j - 1, temp = mat[i][j];
                while ( row < m && col < n && row >= 0 && col >= 0 ) {
                    temp = temp*10 + mat[row][col];
                    if ( prime(temp) ) {
                        vt.push_back(temp);
                        
                    }
                    col--;
                }
                row = i, col = j + 1, temp = mat[i][j];
                while ( row < m && col < n && row >= 0 && col >= 0 ) {
                    temp = temp*10 + mat[row][col];
                    if ( prime(temp) ) {
                        vt.push_back(temp);
                    }
                    col++;

                }
                row = i + 1, col = j - 1, temp = mat[i][j];
                while ( row < m && col < n && row >= 0 && col >= 0 ) {
                    temp = temp*10 + mat[row][col];
                    if ( prime(temp) ) {
                        vt.push_back(temp);
                        
                    }
                    row++;
                    col--;
                }
                row = i + 1, col = j, temp = mat[i][j];
                while ( row < m && col < n && row >= 0 && col >= 0 ) {
                    temp = temp*10 + mat[row][col];
                    if ( prime(temp) ) {
                        vt.push_back(temp);
                        
                    }
                    row++;
                }
                row = i + 1, col = j + 1, temp = mat[i][j];
                while ( row < m && col < n && row >= 0 && col >= 0 ) {
                    temp = temp*10 + mat[row][col];
                    if ( prime(temp) ) {
                        vt.push_back(temp);
                        
                    }
                    row++;
                    col++;
                }
            }
        }
        int dem = 0;
        for ( auto i : vt ) {
            //cout<<i<<" ";
            if ( i > 10 ) mp[i]++;
            dem = max(dem,mp[i]);
        }
        //cout<<'\n';
        sort(vt.begin(),vt.end());
        for ( int i = vt.size() - 1 ; i >= 0 ; --i ) {
            if ( dem == mp[vt[i]] && vt[i] > 10 ) {
                ans = vt[i];
                break;
            }
        }
        return ans;
    }
};
