class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> tmp = {1};
        ans.push_back(tmp);
        for ( int i = 1 ; i < numRows ; ++i ) {
            tmp = ans[ans.size() - 1];
            vector<int> cur;
            cur.push_back(1);
            tmp.push_back(0);
            for ( int j = 1 ; j < tmp.size() ; ++j ) {
                cur.push_back(tmp[j-1] + tmp[j]);
            }
            ans.push_back(cur);
        }
        return ans;
    }
};
