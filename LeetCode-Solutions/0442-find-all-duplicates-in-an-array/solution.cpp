class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> mark(n+1,0),ans;
        for ( auto i : nums ) {
            mark[i]++;
            if ( mark[i] == 2 ) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
