class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n = arr.size();
        set<int> st;
        set<int> ans;
        for ( auto i : arr ) {
            set<int> st1;
            st.insert(0);
            for ( auto j : st ) {
                st1.insert(i | j);
            }
            st = st1;
            for ( auto j : st1 ) {
                ans.insert(j);
            }
        }
        return ans.size();
    }
};
