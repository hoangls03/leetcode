#define ii pair<int,int>
#define fi first 
#define se second
class Solution {
public:
    int calScore(string& s, int start, int endPoint, vector<int>& mark ) {
        int ans = 0;
        for ( int i = start + 1 ; i < endPoint ; ++i ) {
            if ( s[i] == '(' ) {
                int val = calScore(s,i,mark[i],mark);
                i = mark[i];
                if ( val > 0 ) {
                    ans += val*2;
                } else {
                    ans++;
                }
            }
        }
        return ans;
    }
    int scoreOfParentheses(string s) {
        vector<ii> vt;
        int n = s.size();
        stack<int> st;
        vector<int> mark(n);
        for ( int i = 0 ; i < n ; ++i ) {
            if ( s[i] == '(' ) {
                st.push(i);
            } else {
                mark[st.top()] = i;
                st.pop();
            }
        }
        int ans = calScore(s,-1,n,mark);
        return ans;
    }
};
