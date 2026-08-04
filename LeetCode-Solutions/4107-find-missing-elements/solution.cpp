class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> ans;
        for ( int i = 0 ; i < n - 1; ++i ) {
            int tmp = nums[i] + 1;
            while ( tmp != nums[i+1] ) {
                ans.push_back(tmp);
                tmp++;
            }
        }
        return ans;
    }
};
