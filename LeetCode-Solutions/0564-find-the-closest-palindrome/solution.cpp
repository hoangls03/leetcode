class Solution {
public:
    string nearestPalindromic(string s) {
        int n = s.size();
        vector<long long> list;

        string pre =  s.substr(0,(n + 1)/2 );
        long long num = stoll(pre);
        for ( int i = -1 ; i <= 1 ; ++i ) {
            string temp = to_string(num + i);
            string rever = temp;
            reverse(rever.begin(),rever.end());
            if ( n & 1 ) {
                temp += rever.substr(1,rever.size()-1);
            } else {
                temp += rever.substr(0,rever.size());
            }
            list.push_back(stoll(temp));
        }
        num = 1;
        for ( int i = 1 ; i < n ; ++i ) {
            num *= 10;
        }
        list.push_back(num-1);
        num *= 10;
        list.push_back(num+1);
        long long convert = stoll(s);
        long long ans,diff = 1e18;

        for ( auto i : list ) {
            if ( abs(i-convert) <= diff && abs(i-convert) != 0 ) {
                if ( abs(i-convert) == diff ) {
                    ans = min(ans,i);
                } else {
                    ans = i;
                    diff = abs(i-convert);
                }
            }
        }
        return to_string(ans);

    }
};
