class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, sum2 = 0;
        for ( auto i : nums1 ) {
            sum1 += i;
        }
        for ( auto i : nums2 ) {
            sum2 += i;
        }
        if ( sum1 == sum2 ) {
            return 0;
        }
        if ( sum1 > sum2 ) {
            swap(sum1,sum2);
            swap(nums1,nums2);
        }
        vector<int> nums;
        for ( auto i : nums1 ) {
            nums.push_back(6 - i);
        }
        for ( auto i : nums2 ) {
            nums.push_back(i - 1);
        }
        long long diff = sum2 - sum1;
        sort(nums.rbegin(),nums.rend());
       
        int ans = 0;
        for ( auto i : nums ) {
            if ( diff > i ) {
                diff -= i;
                ans++;
            } else {
                diff = 0;
                ans++;
                break;
            }
        }
        if ( diff ) ans = -1;
        return ans;
    }
};
