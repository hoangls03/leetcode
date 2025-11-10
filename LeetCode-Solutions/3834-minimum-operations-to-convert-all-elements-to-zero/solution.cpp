class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int> st;
        int ans = 0;
        for ( auto i : nums ) {
            while ( st.size() && st.top() > i ) {
                st.pop();
            }
            if ( i == 0 ) continue;
            if ( st.empty() || st.top() < i ) {
                ans++;
                st.push(i);
            }
        }
        return ans;
    }
};
