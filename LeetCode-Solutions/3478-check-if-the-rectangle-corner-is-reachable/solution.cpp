class Solution {
public:
    static bool cmp( vector<int>& a, vector<int>& b ) {
        if ( a[1] == b[1] ) {
            if ( a[0] == b[0] ) {
                return a[2] < b[2];
            }
            return a[0] < b[0];
        }
        return a[1] < b[1];
    }
    static bool cmp1( vector<int>& a, vector<int>& b ) {
        if ( a[1] == b[1] ) {
            if ( a[0] == b[0] ) {
                return a[2] < b[2];
            }
            return a[0] < b[0];
        }
        return a[1] > b[1];
    }
    bool check_circles(long long x1, long long y1, long long r1, long long x2, long long y2, long long r2 ) {
        double d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
        if ( d <= r1 - r2 || d <= r1 - r2 || d <= r1 + r2 ) return true;
        return false;
    }
    bool canReachCorner(int X, int Y, vector<vector<int>>& circles) {
        sort(circles.begin(),circles.end());
        int n = circles.size();
        vector<bool> dp(n,false);
        for ( int i = 0 ; i < circles.size() ; ++i ) {
            int x = circles[i][0];
            int y = circles[i][1];
            int r = circles[i][2];
            if ( x - r <= 0 ) dp[i] = true;
            else {
                for ( int j = 0 ; j < i && !dp[i]; ++j ) {
                    int x1 = circles[j][0];
                    int y1 = circles[j][1];
                    int r1 = circles[j][2];
                    if ( check_circles(x,y,r,x1,y1,r1) && dp[j] ) {
                        cout<<x<<" "<<y<<" "<<r<<'\n';
                        cout<<x1<<" "<<y1<<" "<<r1<<'\n';
                        dp[i] = true;
                    }
                }
            }
            if ( x + r >= X && dp[i]  ) {
                return false;
            }
        }

        //case2
        cout<<"check2"<<'\n';
        sort(circles.begin(),circles.end(),cmp);


        for ( int i = 0 ; i < n ; ++i ) 
            dp[i] = false;
        for ( int i = 0 ; i < circles.size() ; ++i ) {
            int x = circles[i][0];
            int y = circles[i][1];
            int r = circles[i][2];
            if ( y - r <= 0 ) dp[i] = true;
            else {
                for ( int j = 0 ; j < i && !dp[i]; ++j ) {
                    int x1 = circles[j][0];
                    int y1 = circles[j][1];
                    int r1 = circles[j][2];
                    if ( check_circles(x,y,r,x1,y1,r1) && dp[j] ) {
                        dp[i] = true;
                    }
                }
            }
            if ( y + r >= Y && dp[i]  ) {
                return false;
            }
        }

        //case3
        cout<<"check3"<<'\n';
        sort(circles.begin(),circles.end(),cmp1);

        for ( int i = 0 ; i < n ; ++i ) 
            dp[i] = false;
        for ( int i = 0 ; i < circles.size() ; ++i ) {
            int x = circles[i][0];
            int y = circles[i][1];
            int r = circles[i][2];
            if ( y + r >= Y ) dp[i] = true;
            else {
                for ( int j = 0 ; j < i && !dp[i]; ++j ) {
                    int x1 = circles[j][0];
                    int y1 = circles[j][1];
                    int r1 = circles[j][2];
                    if ( check_circles(x,y,r,x1,y1,r1) && dp[j] ) {
                        dp[i] = true;
                    }
                }
            }
            if ( x + r >= X && dp[i]  ) {
                return false;
            }
        }

        //case4
        cout<<"check4"<<'\n';
        sort(circles.begin(),circles.end(),cmp1);

        for ( int i = 0 ; i < n ; ++i ) 
            dp[i] = false;
        for ( int i = 0 ; i < circles.size() ; ++i ) {
            int x = circles[i][0];
            int y = circles[i][1];
            int r = circles[i][2];
            if ( x - r <= 0 ) dp[i] = true;
            else {
                for ( int j = 0 ; j < i && !dp[i]; ++j ) {
                    int x1 = circles[j][0];
                    int y1 = circles[j][1];
                    int r1 = circles[j][2];
                    if ( check_circles(x,y,r,x1,y1,r1) && dp[j] ) {
                        dp[i] = true;
                    }
                }
            }
            if ( y - r <= 0 && dp[i]  ) {
                return false;
            }
        }
        return true;
    }
};
