class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        set<int, greater<int>> st;
        bool ok = true;
        for ( auto i : nums1 ) {
            if ( i & 1 ) st.insert(i);
        }
        for ( auto i : nums1 ) {
            if ( i % 2 == 0 ) {
                auto it = st.lower_bound(i);
                if ( it == st.end() ) {
                    ok = false;
                    break;
                }
            }
        }
        if (ok) {
            return true;
        }
        st.clear();
        for ( auto i : nums1 ) {
            if ( i & 1 ) {
                auto it = st.lower_bound(i - 1);
                if ( it == st.end() ) {
                    return false;
                }
            }
        }
        return true;
    }
};
