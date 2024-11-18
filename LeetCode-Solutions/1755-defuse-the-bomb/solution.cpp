class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans;
        int sum = 0;
        for ( int i = 0 ; i < n ; ++i ) {
            sum = 0;
            if ( k == 0 ) {
                ans.push_back(0);
            } else if ( k < 0 ) {
                for ( int j = i - 1 ; j >= i + k ; --j ) {
                    sum += code[(j+n)%n];
                }
                ans.push_back(sum);
            } else {
                for ( int j = i + 1 ; j <= i + k ; ++j ) {
                    sum += code[j%n];
                }
                ans.push_back(sum);
            }
        }
        return ans;
    }
};
