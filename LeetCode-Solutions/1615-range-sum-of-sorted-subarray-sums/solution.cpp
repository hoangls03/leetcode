const int oo = 1e9 + 7;
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<long long> arr;
        for ( int i = 0 ; i < n ; ++i ) {
            long long sum = 0;
            for ( int j = i ; j < n ; ++j ) {
                sum = sum + nums[j];
                arr.push_back(sum);
            }
        }
        sort(arr.begin(),arr.end());
        int ans = 0;
        for ( int i = left - 1 ; i <= right - 1 ; ++i ) {
            ans = (ans + arr[i])%oo;
        }
        return ans;
    }
};
