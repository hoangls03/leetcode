class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> sum(n,0);
        sum[0] = arr[0];
        for ( int i = 1 ; i < n ; ++i ) {
            sum[i] = (sum[i-1]^arr[i]);
        }
        vector<int> ans;
        for ( auto I : queries ) {
            int temp = ( I[0] == 0 ) ? sum[I[1]] : sum[I[1]]^sum[I[0]-1];
            ans.push_back(temp);
        }
        return ans;
    }
};
