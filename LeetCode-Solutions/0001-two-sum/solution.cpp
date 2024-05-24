class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mp;
        vector<int> a(2);
        for ( int i = 0 ; i < nums.size() ; ++i )
        {
            if( mp[target - nums[i]] != 0 )
            {
                a[0] = mp[target-nums[i]] - 1;
                a[1] = i;
            }
            mp[nums[i]] = i + 1;
        }
        return a;
    }
};
