class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.size();
        vector<int> vt;
        for ( int i = 0 ; i <= n ; ++i ) {
            vt.push_back(i+1);
        }
        bool check;
        string ans = "";
        check = true;
        for ( int i = 0 ; i < n && check ; ++i ) {
            if ( pattern[i] == 'I' ) {
                if ( vt[i] > vt[i+1] ) {
                    check = false;
                }
            } else {
                if ( vt[i] < vt[i+1] ) {
                    check = false;
                }
            }
        }
        if ( check ) {
            for ( auto i : vt ) {
                ans += i + '0';
            }
            return ans;
        }
        while ( next_permutation(vt.begin(),vt.end()) ) {
            check = true;
            for ( int i = 0 ; i < n && check ; ++i ) {
                if ( pattern[i] == 'I' ) {
                    if ( vt[i] > vt[i+1] ) {
                        check = false;
                    }
                } else {
                    if ( vt[i] < vt[i+1] ) {
                        check = false;
                    }
                }
            }
            if ( check ) {
                for ( auto i : vt ) {
                    ans += i + '0';
                }
                return ans;
            }
        }
        return ans;
    }
};
