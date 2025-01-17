class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        vector<int> ans(n + 1,0);
        for ( int i = 0 ; i < n ; ++i ) {
            if ( derived[i] == 1 ) {
                ans[i+1] = 1 - ans[i];
            } else {
                ans[i+1] = ans[i];
            }
        }
        return ans[n] == ans[0];
    }
};
