class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int ans = 1e9;
        int n = tops.size();
        for ( int i = 1 ; i <= 6 ; ++i ) {
            int res = 0;
            bool check = true;
            for ( int j = 0 ; j < n && check ; ++j ) {
                if ( tops[j] != i ) {
                    if ( bottoms[j] == i ) {
                        res++;
                    } else {
                        check = false;
                    }

                } 
            }
            if ( check ) {
                ans = min(ans,res);
            }
            res = 0;
            check = true;
            for ( int j = 0 ; j < n && check ; ++j ) {
                if ( bottoms[j] != i ) {
                    if ( tops[j] == i ) {
                        res++;
                    } else {
                        check = false;
                    }

                } 
            }
            if ( check ) {
                ans = min(ans,res);
            }
        }
        return ans == 1e9 ? -1 : ans;
    }
};
