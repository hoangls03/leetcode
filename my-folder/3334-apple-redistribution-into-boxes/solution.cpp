class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n = apple.size();
        int m = capacity.size();
        int sum = 0;
        for ( auto i : apple ) {
            sum += i;
        }
        sort(capacity.begin(),capacity.end());
        int ans = 0;
        for ( int i = m - 1 ; i >= 0 ; --i ) {
            if ( sum > 0 ) {
                ans++;
                sum -= capacity[i];
            }
        }
        return ans;
    }
};
