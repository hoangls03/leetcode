class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int maxNum = 0;
        for ( auto i : nums ) {
            maxNum = max(maxNum,i);
        }

        int maxPow = 1;
        while ( maxPow <= maxNum ) {
            maxPow *= 2;
        }

        vector<int> mark(maxPow);
        int n = nums.size();
        for ( int i = 0 ; i < n ; ++i ) {
            for ( int j = 0 ; j < n ; ++j ) {
                mark[nums[i] ^ nums[j]] = 1;
            }
        }

        vector<int> markAns(maxPow);

        for ( int i = 0 ; i < maxPow ; ++i ) {
            if ( mark[i] ) {
                for ( auto j : nums ) {
                    markAns[i ^ j] = 1;
                }
            }
        }

        int ans = 0;
        for ( int i = 0 ; i < maxPow ; ++i ) {
            if ( markAns[i] ) {
                ans++;
            }
        }

        return ans;
    }
};
