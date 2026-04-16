class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        for ( int i = 0 ; i < n ; ++i ) {
            nums.push_back(nums[i]);
        }
        vector<int> left(2 * n),right(2 * n),leftNear(2 * n),rightNear(2 * n);
        map<int,int> markNear,mark;
        for ( int i = 0 ; i < 2 * n ; ++i ) {
            left[i] = mark[nums[i]] - 1;
            leftNear[i] = markNear[nums[i]] - 1;
            if ( mark[nums[i]] == 0 ) {
                mark[nums[i]] = i + 1;
            }
            markNear[nums[i]] = i + 1;
        }
        mark.clear();
        markNear.clear();
        for ( int i = 2 * n - 1 ; i >= 0 ; --i ) {
            right[i] = mark[nums[i]] - 1;
            rightNear[i] = markNear[nums[i]] - 1;
            if ( mark[nums[i]] == 0 ) {
                mark[nums[i]] = i + 1;
            }
            markNear[nums[i]] = i + 1;
        }
        vector<int> ans;
        for ( auto i : queries ) {
            int left = (leftNear[i] == -1) ? n  : i - leftNear[i];
            int right = (rightNear[i] == -1) ? n  : rightNear[i] - i;
            int tmp = min(left,right);
            left = (leftNear[i + n] == -1) ? n  : i + n  - leftNear[i + n ];
            right = (rightNear[i + n] == -1) ? n  : rightNear[i + n] - (i + n );
            tmp = min({tmp,left,right});
            if ( tmp == n ) tmp = -1;
            ans.push_back(tmp);
        }
        return ans;
    }
};
