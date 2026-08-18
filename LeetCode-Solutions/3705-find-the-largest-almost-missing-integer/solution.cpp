class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = -1;
        vector<int> mark(55,0);
        for ( int i = 0 ; i < n ; ++i ) {
            if ( i + k > n ) {
                continue;
            }
            vector<int> tempMark(55,0);
            for ( int j = i ; j < i + k ; ++j ) {
                tempMark[nums[j]]++;
            }
            for ( int j = 0 ; j <= 50 ; ++j ) {
                mark[j] += ( tempMark[j] != 0 );
            }
        }
        for ( int i = 50 ; i >= 0 ; --i ) {
            if ( mark[i] == 1 ) {
                return i;
            }
        }
        return -1;
    }
};
