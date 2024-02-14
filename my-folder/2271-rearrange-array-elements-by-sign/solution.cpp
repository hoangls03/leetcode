class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        queue<int> q1,q2;
        int n = nums.size();
        for ( int i = 0 ; i < n ; ++i ) { 
            if ( nums[i] < 0 ) q2.push(nums[i]);
            else q1.push(nums[i]);
        }
        vector<int> ans;
        while ( q1.size() ) {
            ans.push_back(q1.front());
            ans.push_back(q2.front());
            q1.pop();
            q2.pop();
        }
        return ans;
    }
};
