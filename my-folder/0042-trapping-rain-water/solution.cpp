class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> l_array(n,0);
        vector<int> r_array(n,0);
        l_array[0] = height[0];
        for ( int i = 1 ; i < n ; ++i ) {
            l_array[i] = max(l_array[i-1],height[i]);
        }
        r_array[n-1] = height[n-1];
        for ( int i = n - 2 ; i >= 0 ; --i ) {
            r_array[i] = max(r_array[i+1],height[i]);
        }
        int ans = 0;
        for ( int i = 0 ; i < n ; ++i ) {
            ans += min(r_array[i],l_array[i]) - height[i];
        }
        return ans;
    }
};
