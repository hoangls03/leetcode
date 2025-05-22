class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        sort(queries.begin(),queries.end());
        priority_queue<int> pq;
        int n = nums.size();
        vector<int> diff(n+1,0);
        int op = 0;
        int pos = 0;
        for ( int i = 0 ; i < nums.size() ; ++i ) {
            op += diff[i];
            while ( pos < queries.size() && queries[pos][0] == i ) {
                pq.push(queries[pos][1]);
                pos++;
            }
            while ( op < nums[i] && pq.size() && pq.top() >= i ) {
                op++;
                diff[pq.top() + 1] -= 1;
                pq.pop();
            }
            if ( op < nums[i] ) {
                return -1;
            }
        }
        return pq.size();
    }
};
