class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans,vt;
        vector<int> count(1e4+1,0);
        sort(nums.begin(),nums.end());
        for ( int i = 0 ; i < nums.size() ; ++i ) {
            count[nums[i]]++;
            if ( count[nums[i]] == 2 ) {
                vt.push_back(nums[i]);
            }
        }
        int go = 0;
        for ( int i = 1 ; i <= n ; ++i ) {
            if ( count[i] == 0 ) {
                ans.push_back(vt[go]);
                ans.push_back(i);
                go++;
            }
        }
        return ans;
    }
};
