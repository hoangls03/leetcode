class Solution {
public:
    bool bk( vector<int>& res, vector<bool>& mark, int n, int index ) {
        while ( index < res.size() && res[index] != 0 ) {
            index++;
        }
        if ( index == res.size() ) {
            return true;
        }
        for ( int i = n ; i >= 1 ; --i ) {
            if ( mark[i] ) continue;
            if ( i == 1 ) {
                res[index] = 1;
                mark[i] = true;
                if ( bk(res,mark,n,index) ) return true;
                res[index] = 0;
                mark[i] = false;
            } else {
                if ( index + i < res.size() && res[index+i] == 0 ) {
                    res[index] = i;
                    res[index + i] = i;
                    mark[i] = true;
                    if ( bk(res,mark,n,index) ) return true;
                    res[index] = 0;
                    res[index+i] = 0;
                    mark[i] = false;
                }
            }
        }
        return false;
    }
    vector<int> constructDistancedSequence(int n) {
        vector<int> res(2*n-1,0);
        vector<bool> mark(n+1,false);
        bk(res,mark,n,0);
        return res;
    }
};
