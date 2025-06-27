class Solution {
public:
    bool valid( string u, string s, int k ) {
        int pos = 0;
        int n = u.size();
        int res = 0;
        for ( char i : s ) {
            if ( i == u[pos] ) {
                pos++;
            }
            if ( pos == n ) {
                pos = 0;
                res++;
            } 
        }
        return (res >= k);
    } 
    string longestSubsequenceRepeatedK(string s, int k) {
        vector<int> freq('z' + 1,0);
        int n = s.size();
        for ( auto i : s ) {
            freq[i]++;
        }
        queue<string> q;
        for ( char i = 'z' ; i >= 'a' ; --i ) {
            if ( freq[i] >= k ) q.push(string(1,i));
        }

        string ans = "";
        while ( q.size() ) {
            string u = q.front();
            q.pop();
            if ( u.size() > ans.size() ) {
                ans = u;
            }
            for ( char i = 'z' ; i >= 'a' ; --i ) {
                if ( freq[i] >= k ) {
                    string v = u + i;
                    if ( valid(v,s,k) ) {
                        q.push(v);
                    }
                }
            }
        }

        return ans;
    }
};
