class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int m = A.size();
        vector<int> ans;
        vector<int> mark(m+1);
        for ( int i = 0 ; i < m ; ++i ) {
            int res = 0;
            mark[A[i]]++;
            for ( int j = 0 ; j <= i ; ++j ) {
                res += mark[B[j]];
            }
            ans.push_back(res);
        }
        return ans;
    }
};
