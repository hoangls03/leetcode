class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> markRight(n);
        for ( int i = 0 ; i < n ; ++i ) {
            markRight[i] = i;
        }

        int pos = 0;
        for ( int i = 0 ; i < n ; ++i ) {
            pos = max(pos,i);
            while ( pos + 1 < n && nums[pos + 1] - nums[pos] <= maxDiff ) {
                pos++;
            }
            markRight[i] = pos;
        }

        vector<bool> ans;
        for ( auto q : queries ) {
            if ( q[0] > q[1] ) {
                swap(q[0],q[1]);
            }
            ans.push_back(markRight[q[0]] >= q[1]);
        }

        return ans;
    }
};
