class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size();
        int count = 1;
        sort(nums.begin(),nums.end());
        vector<int> mark(n,0);
        int temp = nums[0] - 1;
        bool check = true;
        while ( check ) {
            check = false;
            for ( int i = 0 ; i < n ; ++i ) {
                if ( mark[i] == 0 ) {
                    check = true;
                    if ( nums[i] > temp ) {
                        mark[i] = count;
                        temp = nums[i];
                    }
                }
            }
            if ( check ) count++;
            temp = nums[0] - 1;
        }
        vector< vector<int> > ans(count-1);
        for ( int i = 0 ; i < n ; ++i ) {
            ans[mark[i] - 1].push_back(nums[i]);
        }
        return ans;
    }
};
