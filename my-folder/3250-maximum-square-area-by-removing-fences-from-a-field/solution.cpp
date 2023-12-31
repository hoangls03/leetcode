class Solution {
    const int oo = 1e9 + 7;
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        unordered_set<int> st;
        hFences.push_back(1);
        hFences.push_back(m);
        sort(hFences.begin(),hFences.end());
        for ( int i = 0 ; i < hFences.size() ; ++i ) {
            for ( int j = i + 1 ; j < hFences.size() ; ++j ) {
                st.insert(hFences[j]-hFences[i]);
            }
        }
        vFences.push_back(1);
        vFences.push_back(n);
        sort(vFences.begin(),vFences.end());
        long long ans = -1;
        for ( int i = 0 ; i < vFences.size() ; ++i ) {
            for ( int j = i + 1 ; j < vFences.size() ; ++j ) {
                int temp2 = vFences[j]-vFences[i];
                if ( st.count(temp2)  ) {
                    ans = max(ans,(long long)temp2);
                }
            }
        }
        if ( ans == -1 ) return -1;
        return ans*ans%oo;
    }
};
