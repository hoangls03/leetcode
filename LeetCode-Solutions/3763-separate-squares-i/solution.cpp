class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double maxY = 0, total = 0;
        for ( auto& i : squares ) {
            double y = i[1], val = i[2];
            total += val*val;
            maxY = max(maxY,y+val);
        }

        double l = 0, r = maxY;
        total /= 2;
        while ( abs(r -l) > 1e-5 ) {
            double mid = (l + r)/2;
            double area = 0;
            for ( auto& i : squares ) {
                double y = i[1], val = i[2];
                if ( y < mid ) {
                    area += val*min(mid - y, val);
                }
            }
            if ( area >= total ) {
                r = mid;
            } else {
                l = mid;
            }
        }
        return r;
    }
};
