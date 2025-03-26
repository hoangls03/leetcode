class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> save;
        int sum = 0;
        for ( auto i : grid ) {
            for ( auto j : i ) {
                save.push_back(j);
                sum += j;
            }
        }
        sort(save.begin(),save.end());
        int n = save.size();
        bool check = false;
        for ( auto i : save ) {
            if ( ( save[n-1] - i ) % x != 0 ) {
                return -1;
            }
        }        

        int mid = n/2;
        int ans = 0;
        for ( auto i : save ) {
            ans += abs(i-save[n/2])/x;
        }
        return ans;
    }
};
