class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        sort(reservedSeats.begin(),reservedSeats.end());
        int countRow = 0;
        vector<int> seat(15,0);
        seat[reservedSeats[0][1]] = 1;
        int m = reservedSeats.size();
        countRow++;
        int ans = 0;
        for ( int i = 1 ; i < m ; ++i ) {
            if ( reservedSeats[i][0] == reservedSeats[i-1][0] ) {
                seat[reservedSeats[i][1]] = 1;
            } else {
                countRow++;
                for ( int j = 1 ; j <= 10 ; ++j ) {
                    if ( j == 2 || j == 4 || j == 6 ) {
                        bool ok = true;
                        for ( int z = j ; z <= j + 3; ++z ) {
                            if ( seat[z] == 1 ) {
                                ok = false;
                            }
                        }
                        if ( ok ) {
                            ans++;
                            for ( int z = j ; z <= j + 3; ++z ) {
                                seat[z] = 1;
                            }
                        }
                    }
                }
                for ( int j = 1 ; j < 11 ; ++j ) {
                    seat[j] = 0;
                }
                seat[reservedSeats[i][1]] = 1;
            }
        }
        for ( int j = 1 ; j <= 10 ; ++j ) {
            if ( j == 2 || j == 4 || j == 6 ) {
                bool ok = true;
                for ( int z = j ; z <= j + 3; ++z ) {
                    if ( seat[z] == 1 ) {
                        ok = false;
                    }
                }
                if ( ok ) {
                    ans++;
                    for ( int z = j ; z <= j + 3; ++z ) {
                        seat[z] = 1;
                    }
                }
            }
        }
        ans += (n - countRow) * 2;
        return ans;
    }
};
