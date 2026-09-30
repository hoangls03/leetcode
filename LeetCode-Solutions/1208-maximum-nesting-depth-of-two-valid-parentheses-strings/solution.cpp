class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int nest = 0;
        vector<int> ans;
        for ( auto i : seq ) {
            if ( i == '(' ) {
                nest++;
                ans.push_back(nest%2);
            } else {
                ans.push_back(nest%2);
                nest--;
            }
        }
        return ans;
    }
};
