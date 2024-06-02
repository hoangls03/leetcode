class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        for ( int i = 1 ; i <= n/2 ; ++i ) {
            swap(s[i-1],s[n-i]);
        }
    }
};
