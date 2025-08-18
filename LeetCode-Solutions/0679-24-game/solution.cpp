class Solution {
public: 
    bool ok( double n ) {
        return ( abs(n - 24) < 0.1 );
    }
    vector<double> cal(double a, double b) {
        vector<double> ans = {a + b, a - b, a * b};
        if ( b ) ans.push_back(a/b);
        return ans;
    }
    bool check( vector<double> &c ) {
        if ( c.size() == 1 ) return ok(c[0]);
        sort(c.begin(),c.end());
        do {
            vector<double> res = cal(c[0],c[1]);
            for ( auto i : res ) {
                vector<double> tmp = {i};
                for ( int j = 2 ; j < c.size() ; ++j ) {
                    tmp.push_back(c[j]);
                }
                if ( check(tmp) ) return true;
            }
        } while ( next_permutation(c.begin(),c.end()));
        return false;
    }
    bool judgePoint24(vector<int>& cards) {
        vector<double> c(cards.begin(),cards.end());
        return check(c);
    }
};
