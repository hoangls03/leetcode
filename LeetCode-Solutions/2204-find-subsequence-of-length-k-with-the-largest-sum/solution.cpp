#define ii pair<int,int>
#define fi first
#define se second
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<ii> a;
        int n = nums.size();
        for ( int i = 0 ; i < n ; ++i ) {
            a.push_back({nums[i],i});
        }
        sort(a.begin(),a.end());
        vector<int> mark(n,0);
        for ( int i = n - 1 ; i >= n - k ; --i ) {
            mark[a[i].se] = 1;
        }
        vector<int> ans;
        for ( int i = 0 ; i < n ; ++i ) {
            if ( mark[i] == 1 ) {
                ans.push_back(nums[i]);
            }   
        }
        return ans;
    }
};
