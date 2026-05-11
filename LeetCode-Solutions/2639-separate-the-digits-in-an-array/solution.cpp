class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for ( int i = n - 1 ; i >= 0 ; --i ) {
            int tmp = nums[i];
            while ( tmp > 0 ) {
                ans.push_back(tmp%10);
                tmp /= 10;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
