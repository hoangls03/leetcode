#define ii pair<int,int>
#define fi first
#define se second
class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans;
        vector<ii> mark(51);
        for ( int i = 0 ; i <= n - k ; ++i ) {
            for ( int j = 0 ; j <= 50 ; ++j ) {
                mark[j].fi = 0;
                mark[j].se = j;
            }
            for ( int j = i ; j < i + k ; ++j ) {
                mark[nums[j]].fi++;
            }
            sort(mark.begin(),mark.end());
            int temp = x, sum = 0;
            for ( int j = 50 ; j >= 0 ; --j ) {
                if ( temp > 0 ) {
                    sum += mark[j].fi*mark[j].se;
                    temp--;
                }
            }
            ans.push_back(sum);
        }
        return ans;
    }
};
