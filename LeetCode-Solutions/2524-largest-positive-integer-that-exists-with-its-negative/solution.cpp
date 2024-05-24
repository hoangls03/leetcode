class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        map<int,int> mp;
        mp.clear();
        for ( int i = 0 ; i < n ; ++i ) {
            mp[nums[i]]++;
        }
        for ( int i = n - 1 ; i >= 0 ; --i ) {
            if ( mp[-nums[i]] != 0 ) {
                return nums[i];
                break;
            }
        }
        return -1;
    }
};
