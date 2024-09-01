class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int pos = 0;
        vector<vector<int>> ans;
        ans.clear();
        vector<int> temp;
        for ( auto i : original ) {
            pos++;
            temp.push_back(i);
            if ( pos == n ) {
                ans.push_back(temp);
                temp.clear();
                pos = 0;
            }
        }
        if ( ans.size() != m || pos != 0 ) {
            return {};
        }
        return ans;
    }
};
